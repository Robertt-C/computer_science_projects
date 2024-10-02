-- 1
SELECT
  COUNT(*)
FROM 
  Ator 
WHERE 
 sexo = 'f';

-- 2
SELECT
  nomeArt, COUNT(codF)
FROM 
  Ator, Personagem
WHERE 
  Ator.codA = Personagem.codA
GROUP BY 
  nomeArt;

-- 3
SELECT 
  nomeArt, MIN(ano)
FROM 
  Ator, Filme, Personagem
WHERE 
  oscar = 0 AND Ator.codA = Personagem.codA AND Filme.codF = Personagem.codF
GROUP BY 
  nomeArt;


-- 4
SELECT 
  nome, COUNT(codA)
FROM
  Filme, Personagem
WHERE
  Filme.codF = Personagem.codF
GROUP BY
  nome;


-- 5
SELECT
  ano, COUNT(nome)
FROM
  Filme
GROUP BY
  ano;

-- 6
SELECT DISTINCT
  nomeArt
FROM
  Ator, Personagem
WHERE
  Ator.codA = Personagem.codA
  AND
  cache > (
          SELECT
            AVG(cache)
          FROM
            Personagem
          );

-- 7
SELECT
  nomeArt, COUNT(Personagem.codA)
FROM
  Ator, Personagem
WHERE
  Ator.codA = Personagem.codA
GROUP BY
  nomeArt
HAVING COUNT(Personagem.codA) >= 2;