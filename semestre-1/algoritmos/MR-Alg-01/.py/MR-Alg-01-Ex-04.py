largura = float(input("Largura do terreno (em metros): "))
profundidade = float(input("Profundidade do terreno (em metros): "))

area = largura * profundidade
hectares = area / 10000

print(f"O terreno possui {hectares} hectar{hectares != 1 and 'es' or ''}.")