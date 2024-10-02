### Trabalho de Econometria
## Pacotes requisitados
library("stargazer")
library("lmtest")
library("sandwich")
library("psych")
library("MASS")
library("car")



# Dados de escolas:
#   Fonte principal: INEP
#     Retirado de: https://basedosdados.org/dataset/63f1218f-c446-4835-b746-f109a338e3a1?table=08a18c0b-f460-4173-b779-ee422907b9db
# 
# Dados programas sociais:
#   Fonte principal: Ministério da Cidadania
#     Retirado de: https://basedosdados.org/dataset/e12c7b46-6b3b-4658-ba99-1e80d5256938?table=bf2466bb-4b9c-4d34-812d-043b1903203d
# 
# Dados de óbitos:
#   Fonte principal: Sistema de Informações sobre Mortalidade (SIM) \ Ministério da Saúde (MS)
#     Retirado de: https://basedosdados.org/dataset/5beeec93-cbf3-43f6-9eea-9bee6a0d1683?table=dea823a5-cad7-4014-b77c-4aa33b3b0541
# 
# Dados de PIB:
#   Fonte principal: IBGE
#     Retirado de: https://basedosdados.org/dataset/fcf025ca-8b19-4131-8e2d-5ddb12492347?table=fbbbe77e-d234-4113-8af5-98724a956943
#   


## Carregando dados .csv
mortalidade_municipios_2019 <- read.csv("./data/mortalidade_municipais_2019.csv", sep = ',')
familias_bf_2019 <- read.csv("./data/familias_beneficiarias_bf_municipio.csv", sep = ',')
pibs_municipais_2019 <- read.csv("./data/pibs_municipais_2019.csv", sep = ',')
escolas_municipais_2019 <- read.csv("./data/quantidade_escolas_municipio.csv", sep = ',')

## Juntando bases
df <- merge(mortalidade_municipios_2019, familias_bf_2019, by = "id_municipio")
df <- merge(df, pibs_municipais_2019, by = "id_municipio")
df <- merge(df, escolas_municipais_2019, by = "id_municipio")

## Escolhe-se somente as colunas desejadas
df <- subset(df, select = c("id_municipio", "numero_obitos", "familias_beneficiarias", "pib", "quantidade_escolas"))

## Estatísticas descritivas
summary(df)

sd(df$numero_obitos)
sd(df$familias_beneficiarias)
sd(df$pib)
sd(df$quantidade_escolas)

## Execução do modelo linear
model <- lm(numero_obitos ~ familias_beneficiarias + pib + quantidade_escolas, df)

## Testa-se a existência de homocedasticidade
bptest(model)

## Teste de multicolinearidade
vif(model)

## Informações sobre o modelo
summary(model)

stargazer(model, type = "text")