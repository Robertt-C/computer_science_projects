-- Inserir dados na tabela Laboratorio
INSERT INTO Laboratorio 
  (ID_Lab, Nome, Endereco, Contato)
VALUES
(1, 'LabMed', 'Rua dos Análises, 246', 111222333),
(2, 'DiagLab', 'Avenida dos Diagnósticos, 579', 444555666),
(3, 'UltraLab', 'Rua das Ultrassonografias, 013', 777888999),
(4, 'CardioLab', 'Avenida dos Corações, 890', 111222333),
(5, 'GastroLab', 'Rua das Gastroscopias, 135', 444555666),
(6, 'NeuroLab', 'Avenida dos Neurologistas, 246', 777888999),
(7, 'HemoLab', 'Rua dos Hemogramas, 579', 111222333),
(8, 'BioLab', 'Avenida das Biópsias, 890', 444555666),
(9, 'GenoLab', 'Rua dos Genomas, 013', 777888999),
(10, 'ImunoLab', 'Avenida das Imunizações, 246', 111222333);


-- Inserir dados na tabela Departamento
INSERT INTO Departamento 
  (ID_Depto, Nome, Descricao)
VALUES
(1, 'Cardiologia', 'Tratamento de doenças cardíacas'),
(2, 'Ortopedia', 'Tratamento de doenças musculoesqueléticas'),
(3, 'Oftalmologia', 'Tratamento de doenças oculares'),
(4, 'Cirurgia Plástica', 'Procedimentos estéticos e reconstrutivos'),
(5, 'Neurologia', 'Tratamento de doenças neurológicas'),
(6, 'Urologia', 'Tratamento de doenças do trato urinário'),
(7, 'Gastroenterologia', 'Tratamento de doenças gastrointestinais'),
(8, 'Vascular', 'Tratamento de doenças vasculares'),
(9, 'Digestiva', 'Tratamento de doenças do sistema digestivo'),
(10, 'Cardiovascular', 'Tratamento de doenças cardiovasculares');


-- Inserir dados na tabela Funcionario
INSERT INTO Funcionario 
  (ID_Funcionario, Nome, Funcao, Horario, ID_Depto)
VALUES
(401, 'Maria Souza', 'Atendente', '09:00:00', 1),
(402, 'Carlos Santos', 'Recepcionista', '13:30:00', 2),
(403, 'Larissa Oliveira', 'Técnico de Laboratório', '10:00:00', 3),
(404, 'Anderson Lima', 'Auxiliar de Cirurgia', '14:45:00', 4),
(405, 'Cristina Silva', 'Técnico de Radiologia', '11:30:00', 5),
(406, 'Rafaela Costa', 'Enfermeira Cirúrgica', '15:00:00', 6),
(407, 'Paulo Oliveira', 'Enfermeiro Clínico', '08:30:00'),
(408, 'Lucas Pereira', 'Anestesista', '12:15:00', 7),
(409, 'Vanessa Almeida', 'Técnico de Endoscopia', '09:45:00', 8),
(410, 'Fernando Souza', 'Técnico Cardiovascular', '14:00:00', 9);


-- Inserir dados na tabela Enfermeiro
INSERT INTO Enfermeiro 
  (ID_Enfermeiro, Nome, Especialidade, Numero, Horario, ID_Depto)
VALUES
(301, 'Ana Silva', 'Cirúrgico', 101, '08:00:00', 1),
(302, 'José Oliveira', 'Clínico', 102, '12:00:00', 2),
(303, 'Mariana Santos', 'Oftalmologia', 103, '09:30:00', 3),
(304, 'Carlos Lima', 'Plástica', 104, '14:00:00', 4),
(305, 'Fernanda Pereira', 'Neurologia', 105, '10:45:00', 5),
(306, 'Ricardo Sousa', 'Urologia', 106, '15:30:00', 6),
(307, 'Patrícia Costa', 'Gastroenterologia', 107, '08:30:00', 7),
(308, 'Lucas Almeida', 'Vascular', 108, '13:15:00', 8),
(309, 'Juliana Oliveira', 'Digestiva', 109, '11:00:00', 9),
(310, 'Gabriel Santos', 'Cardiovascular', 110, '16:45:00', 10);


-- Inserir dados na tabela Sala
INSERT INTO Sala
  (ID_Sala, Numero, Equipamentos, ID_Depto)
VALUES
(1, 101, 'Mesa cirúrgica, Monitores', 1),
(2, 102, 'Mesa cirúrgica, Equipamentos de Raio-X', 2),
(3, 103, 'Mesa cirúrgica, Equipamentos de Oftalmologia', 1),
(4, 104, 'Mesa cirúrgica, Equipamentos de Cirurgia Plástica', 2),
(5, 105, 'Mesa cirúrgica, Equipamentos de Neurologia', 1),
(6, 106, 'Mesa cirúrgica, Equipamentos de Urologia', 2),
(7, 107, 'Mesa cirúrgica, Equipamentos de Gastroenterologia', 1),
(8, 108, 'Mesa cirúrgica, Equipamentos de Vascular', 2),
(9, 109, 'Mesa cirúrgica, Equipamentos de Digestiva', 1),
(10, 110, 'Mesa cirúrgica, Equipamentos de Cardiovascular', 2);


-- Inserir dados na tabela Medico
INSERT INTO Medico 
  (ID_Medico, Horario, Especialidade, Nome, CRM, ID_Depto)
VALUES
(201, '09:00:00', 'Cardiologia', 'Dr. Roberto Oliveira', 123456, 1),
(202, '13:30:00', 'Ortopedia', 'Dra. Ana Lima', 654321, 2),
(203, '10:00:00', 'Oftalmologia', 'Dr. Pedro Silva', 987654, 3),
(204, '14:45:00', 'Cirurgia Plástica', 'Dra. Renata Costa', 456789, 4),
(205, '11:30:00', 'Neurologia', 'Dr. Camilo Santos', 321098, 5),
(206, '15:00:00', 'Urologia', 'Dra. Isabela Oliveira', 876543, 6),
(207, '08:30:00', 'Gastroenterologia', 'Dr. Marcos Pereira', 109876, 7),
(208, '12:15:00', 'Vascular', 'Dra. Vanessa Souza', 234567, 8),
(209, '09:45:00', 'Digestiva', 'Dr. Rafael Lima', 876543, 9),
(210, '14:00:00', 'Cardiovascular', 'Dra. Juliana Costa', 543210, 10);


-- Inserir dados na tabela Fornecedor
INSERT INTO Fornecedor 
  (ID_Fornecedor, Nome, Endereco, Contato)
VALUES
(1, 'Farmácia ABC', 'Rua Principal, 123', 111222333),
(2, 'Distribuidora XYZ', 'Avenida Secundária, 456', 444555666),
(3, 'Laboratório Saúde', 'Rua da Ciência, 789', 777888999),
(4, 'Imagens & Diagnósticos', 'Avenida Tecnologia, 012', 111222333),
(5, 'Clinic Pharma', 'Rua dos Remédios, 567', 555666777),
(6, 'BioLab', 'Avenida da Pesquisa, 890', 888999000),
(7, 'UltraSaúde', 'Rua do Ultrassom, 135', 123456789),
(8, 'CardioMed', 'Avenida do Coração, 246', 987654321),
(9, 'GastroLab', 'Rua do Endoscópio, 579', 789012345),
(10, 'HemoSangue', 'Avenida das Análises, 013', 321654987);


-- Inserir dados na tabela Medicamento
INSERT INTO Medicamento 
  (ID_Medicamento, Nome, Descricao, QtdMax, ID_Fornecedor)
VALUES
(1, 'Paracetamol', 'Analgésico e antitérmico', 100, 1),
(2, 'Ibuprofeno', 'Anti-inflamatório', 80, 2),
(3, 'Amoxicilina', 'Antibiótico', 60, 3),
(4, 'Dipirona', 'Analgésico', 120, 4),
(5, 'Omeprazol', 'Inibidor de bomba de prótons', 50, 5),
(6, 'Aspirina', 'Anti-inflamatório', 90, 6),
(7, 'Insulina', 'Hormônio', 30, 7),
(8, 'Atorvastatina', 'Estatinas', 40, 8),
(9, 'Metformina', 'Antidiabético', 70, 9),
(10, 'Losartana', 'Anti-hipertensivo', 35, 10);


-- Inserir dados na tabela Enfermaria
INSERT INTO Enfermaria 
  (NumQuarto, Capacidade)
VALUES
(1, 4),
(2, 5),
(3, 3),
(4, 6),
(5, 4),
(6, 5),
(7, 3),
(8, 7),
(9, 4),
(10, 6);


-- Inserir dados na tabela Paciente
INSERT INTO Paciente 
  (ID_Paciente, Telefone, Genero, Nome, CPF, Endereco, DataNasc, NumQuarto)
VALUES
(101, 111222333, 'F', 'Ana Oliveira', 12345678901, 'Rua A, 123', '1980-05-15', 1),
(102, 444555666, 'M', 'Carlos Silva', 23456789012, 'Avenida B, 456', '1975-08-20', 2),
(103, 777888999, 'F', 'Mariana Costa', 34567890123, 'Rua C, 789', '1988-02-10', 3),
(104, 111222333, 'M', 'José Lima', 45678901234, 'Avenida D, 012', '1990-11-05', 4),
(105, 444555666, 'F', 'Fernanda Santos', 56789012345, 'Rua E, 135', '1982-07-20', 5),
(106, 777888999, 'M', 'Ricardo Oliveira', 67890123456, 'Avenida F, 246', '1977-04-08', 6),
(107, 111222333, 'F', 'Patrícia Lima', 78901234567, 'Rua G, 579', '1995-09-30', 7),
(108, 444555666, 'M', 'Lucas Costa', 89012345678, 'Avenida H, 890', '1989-06-15', 8),
(109, 777888999, 'F', 'Juliana Santos', 90123456789, 'Rua I, 013', '1972-03-25', 9),
(110, 111222333, 'M', 'Gabriel Silva', 12345678909, 'Avenida J, 246', '1985-10-18', 10);


-- Inserir dados na tabela Cirurgia
INSERT INTO Cirurgia 
  (ID_Cirurgia, DataCirurgia, Hora, Tipo, Resultados, ID_Paciente, ID_Medico, ID_Sala, ID_Depto)
VALUES
(1, '2023-01-15', '09:00:00', 'Cirurgia Cardíaca', 'Bem-sucedida', 101, 201, 1, 1),
(2, '2023-02-20', '14:30:00', 'Cirurgia Ortopédica', 'Em recuperação', 102, 202, 2, 2),
(3, '2023-03-10', '11:45:00', 'Cirurgia Oftalmológica', 'Sem complicações', 103, 203, 3, 1),
(4, '2023-04-05', '16:20:00', 'Cirurgia Plástica', 'Resultado satisfatório', 104, 204, 4, 2),
(5, '2023-05-20', '10:15:00', 'Cirurgia Geral', 'Recuperação rápida', 105, 205, 1, 1),
(6, '2023-06-08', '15:45:00', 'Cirurgia Neurológica', 'Monitoramento necessário', 106, 206, 2, 2),
(7, '2023-07-12', '08:30:00', 'Cirurgia Cardiovascular', 'Estável pós-operatório', 107, 207, 3, 1),
(8, '2023-08-25', '13:00:00', 'Cirurgia Urológica', 'Aguardando recuperação', 108, 208, 4, 2),
(9, '2023-09-30', '12:15:00', 'Cirurgia Digestiva', 'Complicações mínimas', 109, 209, 1, 1),
(10, '2023-10-18', '14:00:00', 'Cirurgia Vascular', 'Ótima resposta ao tratamento', 110, 210, 2, 2);


-- Inserir dados na tabela Exame
INSERT INTO Exame 
  (ID_Exame, Tipo, Resultado, Data_Exame, Hora_Exame, ID_PAciente, ID_Lab)
VALUES
(1, 'Hemograma', 'Normal', '2023-05-10', '08:30:00', 105, 1),
(2, 'Raio-X', 'Fratura na perna', '2023-06-15', '14:00:00', 106, 2),
(3, 'Tomografia', 'Sem anomalias', '2023-07-20', '09:45:00', 107, 3),
(4, 'Ressonância Magnética', 'Lesão cerebral mínima', '2023-08-25', '15:20:00', 108, 4),
(5, 'Endoscopia', 'Inflamação no estômago', '2023-09-30', '11:15:00', 109, 5),
(6, 'Eletroencefalograma', 'Padrões normais', '2023-10-18', '14:45:00', 110, 6),
(7, 'Ultrassonografia', 'Cisto renal', '2023-11-25', '10:00:00', 111, 7),
(8, 'Ecocardiograma', 'Função cardíaca normal', '2023-12-10', '13:30:00', 112, 8),
(9, 'Colonoscopia', 'Pólipos benignos', '2024-01-05', '12:00:00', 113, 9),
(10, 'Exame de Sangue', 'Valores dentro da faixa normal', '2024-02-12', '15:45:00', 114, 10);


-- Inserir dados na tabela RealizaExame
INSERT INTO RealizaExame 
  (ID_Exame, ID_Lab, ID_Paciente)
VALUES
(1, 1, 105),
(2, 2, 106),
(3, 3, 107),
(4, 4, 108),
(5, 5, 109),
(6, 6, 110),
(7, 7, 111),
(8, 8, 112),
(9, 9, 113),
(10, 10, 114);


-- Inserir dados na tabela Fornece
INSERT INTO Fornece 
  (ID_Medicamento, ID_Paciente, ID_Fornecedor)
VALUES
(1, 105, 1),
(2, 106, 2),
(3, 107, 3),
(4, 108, 4),
(5, 109, 5),
(6, 110, 6),
(7, 111, 7),
(8, 112, 8),
(9, 113, 9),
(10, 114, 10);


-- Inserir dados na tabela RecebeCirurgia
INSERT INTO recebeCirurgia 
  (ID_Cirurgia, ID_Medico, ID_Sala, ID_Depto, ID_Paciente)
VALUES
(1, 201, 1, 1, 101),
(2, 202, 2, 2, 102),
(3, 203, 3, 1, 103),
(4, 204, 4, 2, 104),
(5, 205, 1, 1, 105),
(6, 206, 2, 2, 106),
(7, 207, 3, 1, 107),
(8, 208, 4, 2, 108),
(9, 209, 1, 1, 109),
(10, 210, 2, 2, 110);


INSERT INTO realizaCirurgia 
  (ID_Cirurgia, ID_Medico, ID_Sala, ID_Depto, ID_Paciente)
VALUES
(1, 201, 1, 1, 101),
(2, 202, 2, 2, 102),
(3, 203, 3, 1, 103),
(4, 204, 4, 2, 104),
(5, 205, 1, 1, 105),
(6, 206, 2, 2, 106),
(7, 207, 3, 1, 107),
(8, 208, 4, 2, 108),
(9, 209, 1, 1, 109),
(10, 210, 2, 2, 110);


-- Inserir dados na tabela Consulta
INSERT INTO Consulta 
  (ID_Medico, ID_Depto, ID_Sala, ID_Paciente, ID_Enfermeiro, Diagnostico, DataConsulta, HoraCosulta)
VALUES
(201, 1, 3, 103, 301, 'Pressão alta', '2023-03-10', '10:45:00'),
(202, 2, 4, 104, 302, 'Resfriado', '2023-04-05', '15:20:00'),
(203, 1, 1, 105, 303, 'Lesão muscular', '2023-05-15', '11:30:00'),
(204, 2, 2, 106, 304, 'Infecção respiratória', '2023-06-20', '16:00:00'),
(205, 1, 3, 107, 305, 'Alergia cutânea', '2023-07-25', '09:30:00'),
(206, 2, 4, 108, 306, 'Dor abdominal', '2023-08-30', '14:45:00'),
(207, 1, 1, 109, 307, 'Problemas digestivos', '2023-09-10', '12:00:00'),
(208, 2, 2, 110, 308, 'Dor de cabeça crônica', '2023-10-05', '13:15:00'),
(209, 1, 3, 111, 309, 'Check-up anual', '2023-11-15', '10:00:00'),
(210, 2, 4, 112, 310, 'Distúrbio do sono', '2023-12-20', '15:30:00');


-- Inserir dados na tabela Lotado
INSERT INTO lotado (ID_Medico, ID_Depto, ID_Enfermeiro)
VALUES
(201, 1, 301),
(202, 2, 302),
(203, 1, 303),
(204, 2, 304),
(205, 1, 305),
(206, 2, 306),
(207, 1, 307),
(208, 2, 308),
(209, 1, 309),
(210, 2, 310);