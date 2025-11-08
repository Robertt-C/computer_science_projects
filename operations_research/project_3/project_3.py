import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

print("=" * 80)
print("RESOLUÇÃO DE PROBLEMAS DE PROGRAMAÇÃO LINEAR")
print("MÉTODO SIMPLEX + SOLUÇÃO GRÁFICA")
print("=" * 80)

def simplex_tableau(c, A, b, var_names=None):
    """
    Resolve um problema de PL usando o método Simplex de tabela
    
    Maximizar: c^T * x
    Sujeito a: A * x <= b, x >= 0
    """
    import pandas as pd
    
    # Número de variáveis e restrições
    m, n = A.shape
    
    # Criar tableau inicial
    # [A | I | b]
    # [c | 0 | 0]
    tableau = np.zeros((m + 1, n + m + 1))
    
    # Preencher a matriz de restrições
    tableau[:m, :n] = A
    tableau[:m, n:n+m] = np.eye(m)  # Variáveis de folga
    tableau[:m, -1] = b
    
    # Preencher a linha da função objetivo (negativa para maximização)
    tableau[m, :n] = -c
    
    iteration = 0
    
    if var_names is None:
        var_names = [f'x{i+1}' for i in range(n)]
    
    while True:
        iteration += 1
        print(f"\n{'='*80}")
        print(f"ITERAÇÃO {iteration}")
        print(f"{'='*80}")
        
        # Exibir tableau
        headers = var_names + [f's{i+1}' for i in range(m)] + ['RHS']
        rows = [f'R{i+1}' for i in range(m)] + ['Z']
        df = pd.DataFrame(tableau, columns=headers, index=rows)
        print("\n" + df.to_string())
        
        # Verificar se é ótimo (todos coeficientes na linha Z são >= 0)
        if np.all(tableau[-1, :-1] >= -1e-10):
            print("\n✓ SOLUÇÃO ÓTIMA ENCONTRADA!")
            break
        
        # Encontrar coluna pivô (variável que entra na base)
        pivot_col = np.argmin(tableau[-1, :-1])
        if pivot_col < n:
            print(f"\nVariável que entra: {var_names[pivot_col]}")
        else:
            print(f"\nVariável que entra: s{pivot_col - n + 1}")
        
        # Teste de razão mínima para encontrar linha pivô
        ratios = []
        for i in range(m):
            if tableau[i, pivot_col] > 1e-10:
                ratios.append(tableau[i, -1] / tableau[i, pivot_col])
            else:
                ratios.append(np.inf)
        
        if all(r == np.inf for r in ratios):
            print("\n⚠ PROBLEMA ILIMITADO!")
            return None
        
        pivot_row = np.argmin(ratios)
        print(f"Variável que sai: s{pivot_row + 1}")
        print(f"Elemento pivô: {tableau[pivot_row, pivot_col]:.4f}")
        
        # Operação de pivoteamento
        pivot_element = tableau[pivot_row, pivot_col]
        tableau[pivot_row, :] /= pivot_element
        
        for i in range(m + 1):
            if i != pivot_row:
                multiplier = tableau[i, pivot_col]
                tableau[i, :] -= multiplier * tableau[pivot_row, :]
    
    return tableau

def extract_solution(tableau, n_vars):
    """Extrai a solução ótima do tableau final"""
    m = tableau.shape[0] - 1
    solution = np.zeros(n_vars)
    
    for j in range(n_vars):
        col = tableau[:-1, j]
        if np.sum(np.abs(col) > 1e-10) == 1:  # Variável básica
            basic_row = np.argmax(np.abs(col))
            if abs(col[basic_row] - 1.0) < 1e-10:
                solution[j] = tableau[basic_row, -1]
    
    optimal_value = tableau[-1, -1]
    
    return solution, optimal_value


print("\n" + "=" * 80)
print("ANÁLISE COMPLETA FINALIZADA")
print("=" * 80)

# ============================================================================
# PROBLEMA EMPRESA - ANÁLISE DE VIABILIDADE
# ============================================================================
print("\n\n" + "=" * 80)
print("PROBLEMA DA EMPRESA")
print("=" * 80)
print("""
Uma empresa apresenta o seguinte problema (valores em milhares de euros):

max Z(x) = x₁ + 2x₂
sujeito a:
    2x₁ + x₂ ≤ 2
    x₁, x₂ ≥ 0
""")

# ============================================================================
# QUESTÃO 1 - ANÁLISE TEÓRICA
# ============================================================================
print("\n" + "=" * 80)
print("QUESTÃO 1: Por que é impossível obter lucro de 7000 euros?")
print("=" * 80)
print("""
ANÁLISE TEÓRICA (sem resolver o problema):

1. ANÁLISE DA RESTRIÇÃO:
   - Temos: 2x₁ + x₂ ≤ 2
   - Ou seja: x₂ ≤ 2 - 2x₁

2. ANÁLISE DA FUNÇÃO OBJETIVO:
   - Z = x₁ + 2x₂
   - Substituindo o limite de x₂:
   - Z = x₁ + 2(2 - 2x₁) = x₁ + 4 - 4x₁ = 4 - 3x₁
   
3. MAXIMIZAÇÃO:
   - Como Z = 4 - 3x₁, Z é maximizado quando x₁ é minimizado
   - O menor valor possível é x₁ = 0 (restrição de não-negatividade)
   - Quando x₁ = 0: x₂ ≤ 2 e Z = 0 + 2(2) = 4
   
4. LIMITE SUPERIOR ABSOLUTO:
   - Pela restrição 2x₁ + x₂ ≤ 2, temos:
   - Se x₁ = 0 → x₂ ≤ 2 → Z = 0 + 2(2) = 4
   - Se x₂ = 0 → x₁ ≤ 1 → Z = 1 + 2(0) = 1
   
5. CONCLUSÃO:
   ✗ Z_max ≤ 4 (mil euros) = 4000 euros
   ✗ Portanto, é IMPOSSÍVEL obter lucro de 7000 euros!
   
   O valor máximo possível é 4000 euros, que ocorre em x₁ = 0, x₂ = 2.
""")

# ============================================================================
# QUESTÃO 2 - RESOLUÇÃO PELO MÉTODO SIMPLEX
# ============================================================================
print("\n" + "=" * 80)
print("QUESTÃO 2: Resolução pelo Método Simplex")
print("=" * 80)

# Dados do problema
c_empresa = np.array([1, 2])
A_empresa = np.array([[2, 1]])
b_empresa = np.array([2])

# Resolver pelo Simplex
print("\n" + "-" * 80)
print("APLICAÇÃO DO MÉTODO SIMPLEX")
print("-" * 80)

final_tableau_empresa = simplex_tableau(c_empresa, A_empresa, b_empresa, var_names=['x₁', 'x₂'])

if final_tableau_empresa is not None:
    solution_empresa, optimal_value_empresa = extract_solution(final_tableau_empresa, 2)
    
    print("\n" + "=" * 40)
    print("SOLUÇÃO ÓTIMA - PROBLEMA EMPRESA")
    print("=" * 40)
    print(f"x₁ = {solution_empresa[0]:.2f} (mil euros)")
    print(f"x₂ = {solution_empresa[1]:.2f} (mil euros)")
    print(f"Z_max = {optimal_value_empresa:.2f} (mil euros)")
    print(f"\nLucro máximo = {optimal_value_empresa * 1000:.2f} euros")
    
    print("\n" + "-" * 80)
    print("VERIFICAÇÃO DA SOLUÇÃO:")
    print("-" * 80)
    print(f"Restrição: 2x₁ + x₂ = 2({solution_empresa[0]:.2f}) + {solution_empresa[1]:.2f} = {2*solution_empresa[0] + solution_empresa[1]:.2f} ≤ 2 ✓")
    print(f"Não-negatividade: x₁ = {solution_empresa[0]:.2f} ≥ 0 ✓, x₂ = {solution_empresa[1]:.2f} ≥ 0 ✓")
    print(f"Função objetivo: Z = {solution_empresa[0]:.2f} + 2({solution_empresa[1]:.2f}) = {optimal_value_empresa:.2f} ✓")

# ============================================================================
# SOLUÇÃO GRÁFICA - PROBLEMA EMPRESA
# ============================================================================
fig, ax = plt.subplots(figsize=(10, 8))

x1_emp = np.linspace(0, 3, 400)

# Restrição: 2x₁ + x₂ ≤ 2 => x₂ ≤ 2 - 2x₁
x2_constraint = 2 - 2*x1_emp

# Plotar restrição
ax.plot(x1_emp, x2_constraint, 'r--', linewidth=2, label='2x₁ + x₂ ≤ 2')
ax.fill_between(x1_emp, 0, np.minimum(x2_constraint, 3), where=(x2_constraint >= 0), 
                alpha=0.3, color='lightblue', label='Região Viável')

# Vértices da região viável
vertices_empresa = np.array([[0, 0], [1, 0], [0, 2]])
for i, (x, y) in enumerate(vertices_empresa):
    ax.plot(x, y, 'ko', markersize=10)
    z_vertex = x + 2*y
    ax.annotate(f'({x:.1f}, {y:.1f})\nZ={z_vertex:.1f}', (x, y), 
                xytext=(10, 10), textcoords='offset points', fontsize=10,
                bbox=dict(boxstyle='round', facecolor='yellow', alpha=0.7))

# Solução ótima
if final_tableau_empresa is not None:
    ax.plot(solution_empresa[0], solution_empresa[1], 'r*', markersize=25, 
            label='Solução Ótima', zorder=5)

# Curvas de nível da função objetivo (isocusto)
z_levels = [0, 1, 2, 3, 4]
for z in z_levels:
    # Z = x₁ + 2x₂ => x₂ = (Z - x₁)/2
    x2_iso = (z - x1_emp) / 2
    if z == optimal_value_empresa:
        ax.plot(x1_emp, x2_iso, 'g-', linewidth=3, alpha=0.8, label=f'Z = {z:.1f} (ótimo)')
    else:
        ax.plot(x1_emp, x2_iso, 'gray', linewidth=1, alpha=0.5)
        ax.text(0.5, (z - 0.5) / 2, f'Z={z}', fontsize=8, color='gray')

# Configurações do gráfico
ax.set_xlim(-0.2, 2.5)
ax.set_ylim(-0.2, 3)
ax.set_xlabel('x₁ (mil euros)', fontsize=12)
ax.set_ylabel('x₂ (mil euros)', fontsize=12)
ax.set_title('Problema da Empresa - Solução Gráfica', fontsize=14, fontweight='bold')
ax.grid(True, alpha=0.3)
ax.legend(loc='upper right', fontsize=10)
ax.axhline(y=0, color='k', linewidth=0.5)
ax.axvline(x=0, color='k', linewidth=0.5)

plt.tight_layout()
plt.savefig('problema_empresa_grafico.png', dpi=300, bbox_inches='tight')
print("\n✓ Gráfico salvo: problema_empresa_grafico.png")
plt.close()

# ============================================================================
# ANÁLISE COMPARATIVA COM A AFIRMAÇÃO DO ADMINISTRADOR
# ============================================================================
print("\n" + "=" * 80)
print("ANÁLISE COMPARATIVA")
print("=" * 80)
print(f"""
AFIRMAÇÃO DO ADMINISTRADOR: Lucro de 7000 euros (Z = 7)
RESULTADO OBTIDO: Lucro de {optimal_value_empresa * 1000:.0f} euros (Z = {optimal_value_empresa})

DIFERENÇA: {7 - optimal_value_empresa:.1f} mil euros = {(7 - optimal_value_empresa) * 1000:.0f} euros

CONCLUSÃO:
- A afirmação do administrador está INCORRETA
- O lucro máximo possível é apenas {optimal_value_empresa * 1000:.0f} euros
- O administrador superestimou o lucro em {(7 - optimal_value_empresa) * 1000:.0f} euros
- Erro percentual: {((7 - optimal_value_empresa) / 7) * 100:.1f}%

INTERPRETAÇÃO GEOMÉTRICA:
- A solução ótima ocorre no vértice (0, 2)
- Este é o ponto extremo da região viável que maximiza Z
- A restrição 2x₁ + x₂ ≤ 2 limita severamente as possibilidades
- Qualquer tentativa de aumentar x₁ ou x₂ violaria a restrição
""")

print("\n" + "=" * 80)
print("FIM DA ANÁLISE DO PROBLEMA DA EMPRESA")
print("=" * 80)