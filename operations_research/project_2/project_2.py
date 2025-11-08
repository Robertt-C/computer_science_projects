import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

# Configuração do plot
plt.figure(figsize=(10, 8))
plt.grid(True, linestyle='--', alpha=0.7)

# Limites do gráfico
plt.xlim(-0.5, 7)
plt.ylim(-0.5, 5)

# Criar arrays para plotar as linhas de restrição
x = np.linspace(0, 7, 100)

# Restrição 1: 2x1 + 3x2 ≤ 12
y1 = (12 - 2*x) / 3
mask1 = y1 >= 0
plt.plot(x[mask1], y1[mask1], 'r-', linewidth=2, label='2x₁ + 3x₂ = 12')

# Restrição 2: x1 + 2x2 ≤ 10
y2 = (10 - x) / 2
mask2 = y2 >= 0
plt.plot(x[mask2], y2[mask2], 'b-', linewidth=2, label='x₁ + 2x₂ = 10')

# Eixos
plt.axhline(y=0, color='k', linestyle='-', alpha=0.5)
plt.axvline(x=0, color='k', linestyle='-', alpha=0.5)

# Identificar os vértices da região viável
vertices = [(0, 0), (6, 0), (0, 4)]

# Sombrear a região viável
region = Polygon(vertices, alpha=0.2, color='green', label='Região Viável')
plt.gca().add_patch(region)

# Marcar os vértices
plt.scatter(*zip(*vertices), color='blue', s=100, zorder=5)

# Adicionar rótulos aos vértices
plt.annotate('(0,0)', (0, 0), xytext=(0.1, -0.3), fontsize=12)
plt.annotate('(6,0)', (6, 0), xytext=(5.9, -0.3), fontsize=12)
plt.annotate('(0,4)', (0, 4), xytext=(-0.5, 4), fontsize=12)

# Linha de nível ótima Z = 60 (ligando os pontos ótimos)
plt.plot([0, 6], [4, 0], 'g-', linewidth=3, label='Z = 60 (soluções ótimas)')

# Outras linhas de nível para a função objetivo
z_levels = [20, 40, 80]
for z in z_levels:
    x_z = np.linspace(0, 7, 100)
    y_z = (z - 10*x_z) / 15
    mask = (y_z >= 0) & (x_z >= 0)
    plt.plot(x_z[mask], y_z[mask], 'g--', linewidth=1, alpha=0.6)
    if len(x_z[mask]) > 0:
        plt.annotate(f'Z = {z}', (x_z[mask][-1], y_z[mask][-1]), 
                     xytext=(x_z[mask][-1]+0.1, y_z[mask][-1]), fontsize=10)

# Destacar os pontos ótimos
plt.scatter([0, 6], [4, 0], color='red', s=120, zorder=6, label='Soluções Básicas Ótimas')

# Títulos e legendas
plt.title('Solução Gráfica do Problema de Programação Linear', fontsize=14, fontweight='bold')
plt.xlabel('x₁', fontsize=12)
plt.ylabel('x₂', fontsize=12)
plt.legend(loc='upper right')

plt.tight_layout()
plt.savefig("solucao_grafica_ppl.png", dpi=300)




# # Definindo os limites do gráfico
# x1 = np.linspace(0, 10, 1000)

# # Definindo as restrições
# y1 = x1 + 2          # −x1 + x2 ≤ 2 → x2 ≤ x1 + 2
# y2 = 2*x1 - 6        # 2x1 − x2 ≤ 6 → x2 ≥ 2x1 - 6
# y3 = np.zeros_like(x1)  # x2 ≥ 0

# # Criando a figura
# plt.figure(figsize=(10, 8))

# # Plotando as restrições
# plt.plot(x1, y1, label=r'$x_2 = x_1 + 2$')
# plt.plot(x1, y2, label=r'$x_2 = 2x_1 - 6$')
# plt.plot(x1, y3, label=r'$x_2 = 0$')
# plt.axvline(x=0, color='k', linestyle='-', alpha=0.3)

# # Preenchendo a região factível
# y2_valid = np.maximum(y2, 0)  # Garantindo não-negatividade de x2
# plt.fill_between(x1, y2_valid, y1, where=(x1 >= 0) & (y2_valid <= y1), 
#                  color='skyblue', alpha=0.5, label='Região Factível')

# # Calculando os vértices da região factível
# vertices = [(0, 0), (0, 2), (3, 0)]
# x_intersect = 8  # Ponto onde as linhas x2 = x1 + 2 e x2 = 2x1 - 6 se cruzam
# y_intersect = x_intersect + 2
# vertices.append((x_intersect, y_intersect))

# # Marcando os vértices
# for point in vertices:
#     plt.plot(point[0], point[1], 'ro')
#     plt.annotate(f'({point[0]}, {point[1]})', 
#                  (point[0], point[1]), 
#                  xytext=(5, 5), 
#                  textcoords='offset points')

# # Calculando o valor da função objetivo em cada vértice
# objective_values = [(-v[0] - v[1], v) for v in vertices]
# optimal_value, optimal_point = min(objective_values, key=lambda x: x[0])

# # Destacando a solução ótima
# plt.plot(optimal_point[0], optimal_point[1], 'go', markersize=10)
# plt.annotate(f'Solução ótima: ({optimal_point[0]}, {optimal_point[1]})\nZ = {optimal_value}', 
#              (optimal_point[0], optimal_point[1]), 
#              xytext=(10, -30), 
#              textcoords='offset points',
#              bbox=dict(boxstyle='round', fc='yellow', alpha=0.6))

# # Plotando algumas linhas de contorno da função objetivo
# for z in [-2, -5, -10, -15, -18]:
#     # Z = -x1 - x2 → x2 = -x1 - Z
#     x_obj = np.linspace(0, 10, 100)
#     y_obj = -x_obj - z
#     plt.plot(x_obj, y_obj, 'g--', alpha=0.5)
#     plt.annotate(f'Z = {z}', (5, -5-z), color='green')

# plt.grid(True)
# plt.xlabel('$x_1$')
# plt.ylabel('$x_2$')
# plt.title('Solução Gráfica do Problema de Programação Linear')
# plt.legend()
# plt.axis([0, 10, 0, 12])

# plt.savefig('solucao_grafica_ppl3.png')