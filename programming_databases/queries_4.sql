-- 1
SELECT 
  e.nome
FROM 
  Especialidade e 
  JOIN MedicoEspecialidade me
    ON me.especialidade_cod = e.cod
  JOIN Medico m 
    ON me.medico_cod = m.cod AND m.nome = 'Paulo';

-- 2
SELECT 
  c.`data` 
FROM 
  Consulta c 
  JOIN Medico m 
    ON m.cod = c.medico_cod AND m.nome = 'Arthur';

-- 3
SELECT 
  m.nome, c2.nome, c2.endereco 
FROM 
  Medico m 
JOIN Consulta c
ON m.cod = c.medico_cod 
JOIN Clinica c2 
ON c2.cod = c.clinica_cod
JOIN Especialidade e 
ON e.cod = c.especialidade_cod AND e.nome = 'CLiNiCO GERAL';

-- 5
SELECT 
  c.nome, c.endereco
FROM 
  Clinica c 
  JOIN Consulta c2
  ON c.cod = c2.clinica_cod AND c2.`data` = '2010-03-30';

-- 6
SELECT 
  m.nome
FROM 
  Medico m 
JOIN MedicoClinica mc 
ON m.cod = mc.medico_cod
JOIN Clinica c 
ON c.cod = mc.clinica_cod AND c.nome = 'clinica bem estar';

-- 7
SELECT 
  c.nome, c.endereco
FROM 
  Clinica c 
JOIN MedicoClinica mc
ON c.cod = mc.clinica_cod 
JOIN Medico m 
ON mc.medico_cod = m.cod AND m.nome = 'Andre';

-- 8. Insira 2 clinicas
INSERT INTO Clinica (cod, nome, endereco)
VALUES (11, 'Clinica das Aguas', 'Torto da agua'),
		(12, 'Clinica Bento', 'Rua das carmelitas');

-- 9
INSERT INTO Medico (cod, nome, telefone)
VALUES (12, 'Gabriel', '555-888-7777'),
		(13, 'Marcos', '441-543-6546');
	
-- 10
SELECT 
  c.nome, e.nome
FROM 
  Clinica c 
LEFT JOIN EspecialidadeClinica ec
ON c.cod = ec.clinica_cod LEFT JOIN Especialidade e
ON ec.especialidade_cod = e.cod;
	
-- 11
SELECT 
  c.nome, e.nome
FROM 
  Clinica c 
LEFT JOIN EspecialidadeClinica ec
ON c.cod = ec.especialidade_cod
LEFT JOIN Especialidade e 
ON e.cod = ec.especialidade_cod
ORDER BY c.nome, e.nome;

-- 12
SELECT DISTINCT 
  m.nome, c.`data`
FROM 
  Medico m 
LEFT JOIN Consulta c 
ON m.cod = c.medico_cod;

-- 13
SELECT 
  Medico.nome, COUNT(Consulta.medico_cod)
FROM 
  Medico JOIN Consulta ON (Medico.cod = Consulta.medico_cod)
GROUP BY 
  Medico.nome;

-- 14
SELECT DISTINCT 
  m.nome, COUNT(c.medico_cod)
FROM
  Medico m 
LEFT JOIN Consulta c 
ON m.cod = c.medico_cod
GROUP BY m.cod;

-- 16
SELECT 
  c.nome
FROM 
  Clinica c
JOIN EspecialidadeClinica ec 
ON c.cod = ec.clinica_cod;

-- 17
SELECT 
  Medico.nome
FROM 
  Medico
WHERE 
  Medico.cod NOT IN 
  (
  SELECT 
    Consulta.medico_cod
  FROM 
    Consulta
  );

-- 18
SELECT 
  m.nome
FROM 
  Medico m 
JOIN MedicoClinica mc
ON m.cod = mc.medico_cod 
WHERE mc.clinica_cod 
IN (
	SELECT c.cod
	FROM Clinica c 
	WHERE c.nome = 'ortocentro'
)


-- 19
CREATE TABLE Folha_Pagto( 
	medico_cod int, 
	consulta_cod int, 
	valor float,
	primary key(medico_cod, consulta_cod),
	foreign key (medico_cod) references Medico(cod),
	foreign key (consulta_cod) references Consulta(cod)
);

INSERT INTO Folha_Pagto VALUES (1,1,100), (1,2,150),(2,3,100), (2, 4, 150), (3,5,50);

-- 20
SELECT 
  m.nome
FROM 
  Medico m 
JOIN Folha_Pagto f on m.cod = f.medico_cod
WHERE 
  f.valor > (select AVG(valor) from Folha_Pagto);

-- 21
SELECT 
  Medico.nome
FROM 
  Medico
WHERE 
  Medico.cod NOT IN 
  (
  SELECT 
    Folha_Pagto.medico_cod
  FROM 
    Folha_Pagto
  );

-- 22
SELECT
  m.nome, AVG(f.valor)
FROM 
  Medico m
LEFT JOIN Folha_Pagto f
ON m.cod = f.medico_cod
GROUP BY m.cod;