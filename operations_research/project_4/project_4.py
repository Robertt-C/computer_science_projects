import numpy as np
from typing import Tuple, List

class SimplexSolver:
    def __init__(self):
        self.tableau = None
        self.basic_vars = []
        self.iterations = 0
        
    def print_tableau(self, phase: str = ""):
        """Imprime o tableau atual com formatação de 2 casas decimais"""
        print(f"\n{phase}")
        print("=" * 80)
        
        # Formata o tableau para 2 casas decimais
        formatted_tableau = np.array2string(
            self.tableau, 
            formatter={'float_kind': lambda x: f"{x:8.2f}"},
            suppress_small=True
        )
        print(formatted_tableau)
        print(f"Variáveis básicas: {self.basic_vars}")
        print("=" * 80)
    
    def find_pivot_column(self) -> int:
        """Encontra a coluna pivô (variável de entrada)"""
        # Última linha contém os coeficientes da função objetivo
        last_row = self.tableau[-1, :-1]
        # Procura o valor mais negativo
        min_val = np.min(last_row)
        if min_val >= -1e-10:  # Tolerância numérica
            return -1
        return np.argmin(last_row)
    
    def find_pivot_row(self, pivot_col: int) -> int:
        """Encontra a linha pivô (variável de saída) usando o teste da razão mínima"""
        ratios = []
        for i in range(len(self.tableau) - 1):
            if self.tableau[i, pivot_col] > 1e-10:
                ratio = self.tableau[i, -1] / self.tableau[i, pivot_col]
                ratios.append((ratio, i))
            else:
                ratios.append((float('inf'), i))
        
        if not ratios or all(r[0] == float('inf') for r in ratios):
            return -1
        
        return min(ratios, key=lambda x: x[0])[1]
    
    def pivot(self, pivot_row: int, pivot_col: int):
        """Realiza a operação de pivoteamento"""
        # Normaliza a linha pivô
        pivot_element = self.tableau[pivot_row, pivot_col]
        self.tableau[pivot_row] /= pivot_element
        
        # Elimina os outros elementos da coluna pivô
        for i in range(len(self.tableau)):
            if i != pivot_row:
                multiplier = self.tableau[i, pivot_col]
                self.tableau[i] -= multiplier * self.tableau[pivot_row]
        
        # Atualiza a variável básica
        self.basic_vars[pivot_row] = pivot_col
    
    def solve_phase1(self, A: np.ndarray, b: np.ndarray, artificial_vars: List[int]) -> bool:
        """Fase 1: Minimiza a soma das variáveis artificiais"""
        print("\n" + "="*80)
        print("FASE 1: Minimizando variáveis artificiais")
        print("="*80)
        
        # Modifica a função objetivo para minimizar variáveis artificiais
        self.tableau[-1, :] = 0
        for var_idx in artificial_vars:
            self.tableau[-1, var_idx] = 1
        
        # Ajusta a linha Z para refletir as variáveis básicas iniciais
        for i, basic_var in enumerate(self.basic_vars[:-1]):
            if basic_var in artificial_vars:
                self.tableau[-1] -= self.tableau[i]
        
        self.print_tableau("Tableau Inicial - Fase 1")
        
        # Executa o simplex
        while True:
            pivot_col = self.find_pivot_column()
            if pivot_col == -1:
                break
            
            pivot_row = self.find_pivot_row(pivot_col)
            if pivot_row == -1:
                print("Problema ilimitado!")
                return False
            
            self.iterations += 1
            print(f"\nIteração {self.iterations}: Pivô na linha {pivot_row}, coluna {pivot_col}")
            
            self.pivot(pivot_row, pivot_col)
            self.print_tableau(f"Após Iteração {self.iterations}")
        
        # Verifica se a solução é viável
        if abs(self.tableau[-1, -1]) > 1e-10:
            print(f"\nProblema inviável! Soma de variáveis artificiais = {self.tableau[-1, -1]:.2f}")
            return False
        
        print("\nFase 1 concluída com sucesso! Solução básica viável encontrada.")
        return True
    
    def solve_phase2(self, c: np.ndarray, artificial_vars: List[int]):
        """Fase 2: Otimiza a função objetivo original"""
        print("\n" + "="*80)
        print("FASE 2: Otimizando função objetivo original")
        print("="*80)
        
        # Restaura a função objetivo original
        self.tableau[-1, :] = 0
        self.tableau[-1, :len(c)] = -c
        
        # Ajusta para variáveis básicas
        for i, basic_var in enumerate(self.basic_vars[:-1]):
            if basic_var < len(c) and basic_var not in artificial_vars:
                self.tableau[-1] -= c[basic_var] * self.tableau[i]
        
        self.iterations = 0
        self.print_tableau("Tableau Inicial - Fase 2")
        
        # Executa o simplex
        while True:
            pivot_col = self.find_pivot_column()
            if pivot_col == -1:
                break
            
            pivot_row = self.find_pivot_row(pivot_col)
            if pivot_row == -1:
                print("Problema ilimitado!")
                return False
            
            self.iterations += 1
            print(f"\nIteração {self.iterations}: Pivô na linha {pivot_row}, coluna {pivot_col}")
            
            self.pivot(pivot_row, pivot_col)
            self.print_tableau(f"Após Iteração {self.iterations}")
        
        return True
    
    def two_phase_simplex(self, c: np.ndarray, A: np.ndarray, b: np.ndarray, 
                          slack_vars: int, surplus_vars: List[int], artificial_vars: List[int]):
        """Método Simplex de Duas Fases"""
        print("\n" + "#"*80)
        print("MÉTODO SIMPLEX - DUAS FASES")
        print("#"*80)
        
        num_vars = A.shape[1]
        num_constraints = A.shape[0]
        
        # Cria o tableau inicial
        self.tableau = np.zeros((num_constraints + 1, num_vars + 1))
        self.tableau[:-1, :-1] = A
        self.tableau[:-1, -1] = b
        
        # Define variáveis básicas iniciais (artificiais)
        self.basic_vars = artificial_vars.copy() + [num_vars]
        
        # Fase 1
        if not self.solve_phase1(A, b, artificial_vars):
            return None
        
        # Remove colunas de variáveis artificiais para Fase 2
        cols_to_keep = [i for i in range(num_vars) if i not in artificial_vars] + [-1]
        self.tableau = self.tableau[:, cols_to_keep]
        
        # Ajusta índices das variáveis básicas
        artificial_set = set(artificial_vars)
        adjustment = [sum(1 for a in artificial_vars if a < bv) for bv in self.basic_vars]
        self.basic_vars = [bv - adj if bv not in artificial_set else bv 
                          for bv, adj in zip(self.basic_vars, adjustment)]
        
        # Fase 2
        c_adjusted = np.delete(c, artificial_vars)
        if not self.solve_phase2(c_adjusted, artificial_vars):
            return None
        
        return self.get_solution(len(c_adjusted))
    
    def big_m_simplex(self, c: np.ndarray, A: np.ndarray, b: np.ndarray,
                      slack_vars: int, surplus_vars: List[int], artificial_vars: List[int]):
        """Método Big-M"""
        print("\n" + "#"*80)
        print("MÉTODO SIMPLEX - BIG M")
        print("#"*80)
        
        M = 1e6  # Valor grande para penalizar variáveis artificiais
        
        num_vars = A.shape[1]
        num_constraints = A.shape[0]
        
        # Cria o tableau inicial
        self.tableau = np.zeros((num_constraints + 1, num_vars + 1))
        self.tableau[:-1, :-1] = A
        self.tableau[:-1, -1] = b
        self.tableau[-1, :len(c)] = -c
        
        # Adiciona penalização Big-M para variáveis artificiais
        for var_idx in artificial_vars:
            self.tableau[-1, var_idx] = M
        
        # Define variáveis básicas iniciais
        self.basic_vars = artificial_vars.copy() + [num_vars]
        
        # Ajusta linha Z para variáveis básicas iniciais
        for i, basic_var in enumerate(self.basic_vars[:-1]):
            if basic_var in artificial_vars:
                self.tableau[-1] -= M * self.tableau[i]
        
        self.print_tableau("Tableau Inicial - Big M")
        
        # Executa o simplex
        self.iterations = 0
        while True:
            pivot_col = self.find_pivot_column()
            if pivot_col == -1:
                break
            
            pivot_row = self.find_pivot_row(pivot_col)
            if pivot_row == -1:
                print("Problema ilimitado!")
                return None
            
            self.iterations += 1
            print(f"\nIteração {self.iterations}: Pivô na linha {pivot_row}, coluna {pivot_col}")
            
            self.pivot(pivot_row, pivot_col)
            self.print_tableau(f"Após Iteração {self.iterations}")
        
        return self.get_solution(len(c))
    
    def get_solution(self, num_original_vars: int) -> dict:
        """Extrai a solução do tableau"""
        solution = np.zeros(num_original_vars)
        for i, var_idx in enumerate(self.basic_vars[:-1]):
            if var_idx < num_original_vars:
                solution[var_idx] = self.tableau[i, -1]
        
        objective_value = self.tableau[-1, -1]
        
        return {
            'x': solution,
            'objective': objective_value,
            'basic_vars': self.basic_vars[:-1]
        }


def solve_problem():
    """
    Resolve o problema:
    max 2x1 + 5x2 + x3
    s.t.
    x1 + x2 ≥ 6
    x2 - x3 ≥ 4
    4x1 + 2x2 + x3 ≤ 15
    x1, x2, x3 ≥ 0
    """
    
    # Coeficientes da função objetivo (maximização -> minimizar -Z)
    c = np.array([2, 5, 1])
    
    # Convertendo para forma padrão:
    # Restrição 1: x1 + x2 - s1 + a1 = 6 (≥)
    # Restrição 2: x2 - x3 - s2 + a2 = 4 (≥)
    # Restrição 3: 4x1 + 2x2 + x3 + s3 = 15 (≤)
    
    A = np.array([
        [1,  1,  0, -1,  0,  0,  1,  0],  # x1, x2, x3, s1, s2, s3, a1, a2
        [0,  1, -1,  0, -1,  0,  0,  1],
        [4,  2,  1,  0,  0,  1,  0,  0]
    ])
    
    b = np.array([6, 4, 15])
    
    # Estende c para incluir variáveis de folga e artificiais
    c_extended = np.concatenate([c, np.zeros(5)])  # s1, s2, s3, a1, a2
    
    slack_vars = 3  # s1, s2, s3
    surplus_vars = [3, 4]  # índices de s1 e s2
    artificial_vars = [6, 7]  # índices de a1 e a2
    
    # Método de Duas Fases
    print("\n" + "█"*80)
    print("RESOLUÇÃO DO PROBLEMA")
    print("█"*80)
    solver1 = SimplexSolver()
    result1 = solver1.two_phase_simplex(c_extended, A.copy(), b.copy(), 
                                        slack_vars, surplus_vars, artificial_vars)
    
    if result1:
        print("\n" + "="*80)
        print("SOLUÇÃO FINAL - DUAS FASES")
        print("="*80)
        print(f"x1 = {result1['x'][0]:.2f}")
        print(f"x2 = {result1['x'][1]:.2f}")
        print(f"x3 = {result1['x'][2]:.2f}")
        print(f"Valor Ótimo (Z) = {result1['objective']:.2f}")
    
    # Método Big-M
    print("\n\n")
    solver2 = SimplexSolver()
    result2 = solver2.big_m_simplex(c_extended, A.copy(), b.copy(),
                                    slack_vars, surplus_vars, artificial_vars)
    
    if result2:
        print("\n" + "="*80)
        print("SOLUÇÃO FINAL - BIG M")
        print("="*80)
        print(f"x1 = {result2['x'][0]:.2f}")
        print(f"x2 = {result2['x'][1]:.2f}")
        print(f"x3 = {result2['x'][2]:.2f}")
        print(f"Valor Ótimo (Z) = {result2['objective']:.2f}")


if __name__ == "__main__":
    solve_problem()