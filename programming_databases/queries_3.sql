-- 1
SELECT 
  Medico.nome, COUNT(Clinica.cod)
FROM
  MedicoClinica
JOIN 
  Medico
    ON
      (Medico.cod = MedicoClinica.medico_cod)
JOIN
  Clinica
    ON
      (Clinica.cod = MedicoClinica.clinica_cod)
GROUP BY
  Medico.nome
ORDER BY
  Medico.nome ASC;


-- 2
SELECT
  Medico.nome
FROM
  Medico
WHERE
  EXISTS
    (
    SELECT 
      MedicoEspecialidade.medico_cod, COUNT(MedicoEspecialidade.medico_cod)
    FROM
      MedicoEspecialidade
    WHERE 
      MedicoEspecialidade.medico_cod = Medico.cod
    GROUP BY 
      MedicoEspecialidade.medico_cod
    HAVING 
      COUNT(MedicoEspecialidade.medico_cod) = 2
    );


-- 3
SELECT
  Clinica.nome
FROM 
  Clinica
WHERE
  EXISTS
  (
  SELECT 
    AVG(Consulta.hora)
  FROM 
    Consulta
  WHERE
    Consulta.clinica_cod = Clinica.cod
  HAVING 
    AVG(Consulta.hora) > 20
  );


-- 4
SELECT 
  Clinica.nome, Especialidade.nome
FROM 
  Clinica, Especialidade, EspecialidadeClinica
WHERE
  Clinica.cod = EspecialidadeClinica.clinica_cod
  AND 
  Especialidade.cod = EspecialidadeClinica.especialidade_cod;


-- 5
SELECT 
  Clinica.nome, COUNT(Especialidade.nome)
FROM 
  Clinica, Especialidade, EspecialidadeClinica
WHERE
  Clinica.cod = EspecialidadeClinica.clinica_cod
  AND 
  Especialidade.cod = EspecialidadeClinica.especialidade_cod
GROUP BY Clinica.nome;


-- 6
SELECT 
  Clinica.nome
FROM 
  Clinica, Medico, MedicoClinica
WHERE
  Clinica.cod = MedicoClinica.clinica_cod
  AND
  Medico.cod = MedicoClinica.medico_cod
  AND
  Medico.nome = "Arthur";


-- 7
SELECT
  Especialidade.nome
FROM 
  Especialidade, Medico, MedicoEspecialidade
WHERE
  Especialidade.cod = MedicoEspecialidade.especialidade_cod
  AND
  Medico.cod = MedicoEspecialidade.medico_cod
  AND
  Medico.nome = "Andre";


-- 8
SELECT 
  Medico.nome
FROM 
  Medico, Consulta
WHERE
  Medico.cod = Consulta.medico_cod
  AND 
  Consulta.hora BETWEEN "23:00:00" AND "00:00:00";


-- 9
SELECT 
  Medico.nome
FROM
  Medico
WHERE
  Medico.cod
  NOT IN
  (
  SELECT 
    MedicoClinica.medico_cod
  FROM 
    MedicoClinica
  );