Enter password: 
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Cirurgia` (
  `ID_Cirurgia` int(11) NOT NULL,
  `DataCirurgia` date DEFAULT NULL,
  `Hora` time DEFAULT NULL,
  `Tipo` varchar(20) DEFAULT NULL,
  `Resultados` varchar(100) DEFAULT NULL,
  `ID_Paciente` int(11) NOT NULL,
  `ID_Medico` int(11) NOT NULL,
  `ID_Sala` int(11) NOT NULL,
  `ID_Depto` int(11) NOT NULL,
  PRIMARY KEY (`ID_Cirurgia`,`ID_Paciente`,`ID_Medico`,`ID_Sala`,`ID_Depto`),
  KEY `ID_Paciente` (`ID_Paciente`),
  KEY `ID_Medico` (`ID_Medico`),
  KEY `ID_Sala` (`ID_Sala`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `Cirurgia_ibfk_1` FOREIGN KEY (`ID_Paciente`) REFERENCES `Paciente` (`ID_Paciente`),
  CONSTRAINT `Cirurgia_ibfk_2` FOREIGN KEY (`ID_Medico`) REFERENCES `Medico` (`ID_Medico`),
  CONSTRAINT `Cirurgia_ibfk_3` FOREIGN KEY (`ID_Sala`) REFERENCES `Sala` (`ID_Sala`),
  CONSTRAINT `Cirurgia_ibfk_4` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Consulta` (
  `ID_Medico` int(11) NOT NULL,
  `ID_Depto` int(11) NOT NULL,
  `ID_Sala` int(11) DEFAULT NULL,
  `ID_Paciente` int(11) NOT NULL,
  `ID_Enfermeiro` int(11) NOT NULL,
  `Diagnostico` varchar(100) DEFAULT NULL,
  `DataConsulta` date DEFAULT NULL,
  `HoraCosulta` time DEFAULT NULL,
  PRIMARY KEY (`ID_Enfermeiro`,`ID_Medico`,`ID_Paciente`,`ID_Depto`),
  KEY `ID_Paciente` (`ID_Paciente`),
  KEY `ID_Sala` (`ID_Sala`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `Consulta_ibfk_1` FOREIGN KEY (`ID_Enfermeiro`) REFERENCES `Enfermeiro` (`ID_Enfermeiro`),
  CONSTRAINT `Consulta_ibfk_2` FOREIGN KEY (`ID_Paciente`) REFERENCES `Paciente` (`ID_Paciente`),
  CONSTRAINT `Consulta_ibfk_3` FOREIGN KEY (`ID_Sala`) REFERENCES `Sala` (`ID_Sala`),
  CONSTRAINT `Consulta_ibfk_4` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Departamento` (
  `ID_Depto` int(11) NOT NULL,
  `Nome` varchar(30) DEFAULT NULL,
  `Descricao` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Enfermaria` (
  `NumQuarto` int(11) NOT NULL,
  `Capacidade` int(11) DEFAULT NULL,
  PRIMARY KEY (`NumQuarto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Enfermeiro` (
  `ID_Enfermeiro` int(11) NOT NULL,
  `Nome` varchar(30) DEFAULT NULL,
  `Especialidade` varchar(30) DEFAULT NULL,
  `Numero` int(11) DEFAULT NULL,
  `Horario` time DEFAULT NULL,
  `ID_Depto` int(11) NOT NULL,
  PRIMARY KEY (`ID_Enfermeiro`,`ID_Depto`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `Enfermeiro_ibfk_1` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Exame` (
  `ID_Exame` int(11) NOT NULL,
  `Tipo` varchar(20) DEFAULT NULL,
  `Resultado` varchar(30) DEFAULT NULL,
  `Data_Exame` date DEFAULT NULL,
  `Hora_Exame` time DEFAULT NULL,
  `ID_PAciente` int(11) NOT NULL,
  `ID_Lab` int(11) NOT NULL,
  PRIMARY KEY (`ID_Exame`,`ID_PAciente`,`ID_Lab`),
  KEY `ID_PAciente` (`ID_PAciente`),
  KEY `ID_Lab` (`ID_Lab`),
  CONSTRAINT `Exame_ibfk_1` FOREIGN KEY (`ID_PAciente`) REFERENCES `Paciente` (`ID_Paciente`),
  CONSTRAINT `Exame_ibfk_2` FOREIGN KEY (`ID_Lab`) REFERENCES `Laboratorio` (`ID_Lab`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Fornece` (
  `ID_Medicamento` int(11) NOT NULL,
  `ID_Paciente` int(11) DEFAULT NULL,
  `ID_Fornecedor` int(11) NOT NULL,
  PRIMARY KEY (`ID_Medicamento`,`ID_Fornecedor`),
  KEY `ID_Fornecedor` (`ID_Fornecedor`),
  CONSTRAINT `Fornece_ibfk_1` FOREIGN KEY (`ID_Medicamento`) REFERENCES `Medicamento` (`ID_Medicamento`),
  CONSTRAINT `Fornece_ibfk_2` FOREIGN KEY (`ID_Fornecedor`) REFERENCES `Fornecedor` (`ID_Fornecedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Fornecedor` (
  `ID_Fornecedor` int(11) NOT NULL,
  `Nome` varchar(20) DEFAULT NULL,
  `Endereco` varchar(30) DEFAULT NULL,
  `Contato` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Fornecedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Funcionario` (
  `ID_Funcionario` int(11) NOT NULL,
  `Nome` varchar(30) DEFAULT NULL,
  `Funcao` varchar(30) DEFAULT NULL,
  `Horario` time DEFAULT NULL,
  `ID_Depto` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Funcionario`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `Funcionario_ibfk_1` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Laboratorio` (
  `ID_Lab` int(11) NOT NULL,
  `Nome` varchar(20) DEFAULT NULL,
  `Endereco` varchar(30) DEFAULT NULL,
  `Contato` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Lab`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Medicamento` (
  `ID_Medicamento` int(11) NOT NULL,
  `Nome` varchar(20) DEFAULT NULL,
  `Descricao` varchar(100) DEFAULT NULL,
  `QtdMax` int(11) DEFAULT NULL,
  `ID_Fornecedor` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Medicamento`),
  KEY `ID_Fornecedor` (`ID_Fornecedor`),
  CONSTRAINT `Medicamento_ibfk_1` FOREIGN KEY (`ID_Fornecedor`) REFERENCES `Fornecedor` (`ID_Fornecedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Medico` (
  `ID_Medico` int(11) NOT NULL,
  `Horario` time DEFAULT NULL,
  `Especialidade` varchar(30) DEFAULT NULL,
  `Nome` varchar(30) DEFAULT NULL,
  `CRM` int(11) DEFAULT NULL,
  `ID_Depto` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Medico`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `Medico_ibfk_1` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Paciente` (
  `ID_Paciente` int(11) NOT NULL,
  `Telefone` int(11) DEFAULT NULL,
  `Genero` varchar(1) DEFAULT NULL,
  `Nome` varchar(30) DEFAULT NULL,
  `CPF` int(11) DEFAULT NULL,
  `Endereco` varchar(30) DEFAULT NULL,
  `DataNasc` date DEFAULT NULL,
  `NumQuarto` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Paciente`),
  KEY `NumQuarto` (`NumQuarto`),
  CONSTRAINT `Paciente_ibfk_1` FOREIGN KEY (`NumQuarto`) REFERENCES `Enfermaria` (`NumQuarto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RealizaExame` (
  `ID_Exame` int(11) NOT NULL,
  `ID_Lab` int(11) NOT NULL,
  `ID_Paciente` int(11) NOT NULL,
  PRIMARY KEY (`ID_Exame`,`ID_Paciente`,`ID_Lab`),
  KEY `ID_Paciente` (`ID_Paciente`),
  KEY `ID_Lab` (`ID_Lab`),
  CONSTRAINT `RealizaExame_ibfk_1` FOREIGN KEY (`ID_Paciente`) REFERENCES `Paciente` (`ID_Paciente`),
  CONSTRAINT `RealizaExame_ibfk_2` FOREIGN KEY (`ID_Lab`) REFERENCES `Laboratorio` (`ID_Lab`),
  CONSTRAINT `RealizaExame_ibfk_3` FOREIGN KEY (`ID_Exame`) REFERENCES `Exame` (`ID_Exame`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Sala` (
  `ID_Sala` int(11) NOT NULL,
  `Numero` int(11) DEFAULT NULL,
  `Equipamentos` varchar(50) DEFAULT NULL,
  `ID_Depto` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID_Sala`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `Sala_ibfk_1` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `lotado` (
  `ID_Medico` int(11) NOT NULL,
  `ID_Depto` int(11) DEFAULT NULL,
  `ID_Enfermeiro` int(11) NOT NULL,
  PRIMARY KEY (`ID_Enfermeiro`,`ID_Medico`),
  KEY `ID_Medico` (`ID_Medico`),
  KEY `ID_Depto` (`ID_Depto`),
  CONSTRAINT `lotado_ibfk_1` FOREIGN KEY (`ID_Enfermeiro`) REFERENCES `Enfermeiro` (`ID_Enfermeiro`),
  CONSTRAINT `lotado_ibfk_2` FOREIGN KEY (`ID_Medico`) REFERENCES `Medico` (`ID_Medico`),
  CONSTRAINT `lotado_ibfk_3` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `realizaCirurgia` (
  `ID_Cirurgia` int(11) NOT NULL,
  `ID_Medico` int(11) NOT NULL,
  `ID_Sala` int(11) NOT NULL,
  `ID_Depto` int(11) NOT NULL,
  `ID_Paciente` int(11) NOT NULL,
  PRIMARY KEY (`ID_Cirurgia`,`ID_Medico`,`ID_Sala`,`ID_Depto`,`ID_Paciente`),
  KEY `ID_Medico` (`ID_Medico`),
  KEY `ID_Sala` (`ID_Sala`),
  KEY `ID_Depto` (`ID_Depto`),
  KEY `ID_Paciente` (`ID_Paciente`),
  CONSTRAINT `realizaCirurgia_ibfk_1` FOREIGN KEY (`ID_Cirurgia`) REFERENCES `Cirurgia` (`ID_Cirurgia`),
  CONSTRAINT `realizaCirurgia_ibfk_2` FOREIGN KEY (`ID_Medico`) REFERENCES `Medico` (`ID_Medico`),
  CONSTRAINT `realizaCirurgia_ibfk_3` FOREIGN KEY (`ID_Sala`) REFERENCES `Sala` (`ID_Sala`),
  CONSTRAINT `realizaCirurgia_ibfk_4` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`),
  CONSTRAINT `realizaCirurgia_ibfk_5` FOREIGN KEY (`ID_Paciente`) REFERENCES `Paciente` (`ID_Paciente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `recebeCirurgia` (
  `ID_Cirurgia` int(11) NOT NULL,
  `ID_Medico` int(11) NOT NULL,
  `ID_Sala` int(11) NOT NULL,
  `ID_Depto` int(11) NOT NULL,
  `ID_Paciente` int(11) NOT NULL,
  PRIMARY KEY (`ID_Cirurgia`,`ID_Medico`,`ID_Sala`,`ID_Depto`,`ID_Paciente`),
  KEY `ID_Medico` (`ID_Medico`),
  KEY `ID_Sala` (`ID_Sala`),
  KEY `ID_Depto` (`ID_Depto`),
  KEY `ID_Paciente` (`ID_Paciente`),
  CONSTRAINT `recebeCirurgia_ibfk_1` FOREIGN KEY (`ID_Cirurgia`) REFERENCES `Cirurgia` (`ID_Cirurgia`),
  CONSTRAINT `recebeCirurgia_ibfk_2` FOREIGN KEY (`ID_Medico`) REFERENCES `Medico` (`ID_Medico`),
  CONSTRAINT `recebeCirurgia_ibfk_3` FOREIGN KEY (`ID_Sala`) REFERENCES `Sala` (`ID_Sala`),
  CONSTRAINT `recebeCirurgia_ibfk_4` FOREIGN KEY (`ID_Depto`) REFERENCES `Departamento` (`ID_Depto`),
  CONSTRAINT `recebeCirurgia_ibfk_5` FOREIGN KEY (`ID_Paciente`) REFERENCES `Paciente` (`ID_Paciente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;