-- 1
SELECT 
  *
FROM 
  Ator
WHERE 
  sexo = 'f';
  
-- 2
SELECT 
  nomeArt, nacionalidade, sexo
FROM 
  Ator;

-- 3
SELECT 
  nome, indicacoesOscar, oscar
FROM 
  Ator;

-- 4
SELECT 
  DISTINTCT
FROM 
  Personagem
WHERE
  cache <= 3000;
  
-- 5
SELECT
  personagem
FROM
  Ator, Personagem
WHERE
  nomeArt = "DemiMoore" AND Ator.codA = Personagem.codA;
  
-- 6
SELECT
  nome
FROM
  Ator, Personagem, Filme
WHERE
  nomeArt = "DemiMoore" AND Ator.codA = Personagem.codA AND Filme.codF = Personagem.codF;
  
-- 7
SELECT
  nomeArt
FROM
  Ator
WHERE
  TRIM(LEFT(nomeReal , 7)) = "Jessica";
  
-- 8
SELECT
  nomeArt
FROM
  Ator
WHERE
  idade BETWEEN 30 AND 40;
  
-- 9
SELECT
  nomeArt
FROM
  Ator
WHERE
  indicacoesOscar = oscar + 2;
  
-- 10
SELECT
  nomeArt
FROM
  Ator
ORDER BY 
  nomeArt;

-- 11
SELECT
  *
FROM
  Ator
WHERE
  sexo = 'f'
ORDER BY
  idade DESC,
  nomeArt ASC;
  
-- 12
SELECT
  nomeArt, nacionalidade
FROM 
  Ator
WHERE
  EXISTS
    (
    SELECT
      *
    FROM
      Filme
    WHERE
      codA = Ator.codA
    );