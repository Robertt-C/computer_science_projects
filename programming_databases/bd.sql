CREATE TABLE Ator
(
  codA INT AUTO_INCREMENT,
  nomeArt VARCHAR(255),
  nomeReal VARCHAR(255),
  nacionalidade VARCHAR(255),
  sexo VARCHAR(255),
  idade INT,
  indicacoesOscar INT,
  oscar INT,
  
  PRIMARY KEY (codA)
);


CREATE TABLE Filme
(
  codF INT AUTO_INCREMENT,
  nome VARCHAR(255),
  ano INT,
  orcamento INT,
  tempo INT,
  
  PRIMARY KEY (codF)
);


CREATE TABLE Personagem
(
  codA INT,
  codF INT,
  personagem VARCHAR(255),
  cache INT,
  
  FOREIGN KEY (codA) REFERENCES Ator(codA) ON DELETE CASCADE,
  FOREIGN KEY (codF) REFERENCES Filme(codF) ON DELETE CASCADE
);




INSERT INTO Ator 
  (nomeArt, nomeReal, nacionalidade, sexo, idade, indicacoesOscar, oscar)
VALUES
  ('DemiMoore', 'MariadaSilva', 'USA', 'f', 32, 0, 0),
  ('BradPitt', 'JoaoPaulo', 'USA', 'f', 28, 1, 0),
  ('DustinHoffman', 'DustinHoffman', 'USA', 'f', 36, 2, 0),
  ('JessicaLange', 'JessicaLange', 'USA', 'f', 42, 4, 2),
  ('SoniaBraga', 'SoniaBraga', 'Brasil', 'f', 45, 0, 0);
  

INSERT INTO Filme
  (nome, ano, orcamento, tempo)
VALUES
  ('AJurada', 1996, 1000000, 18),
  ('ALetraEscarlate', 1995, 10000000, 24),
  ('Seven', 1995, 1500000, 20),
  ('Tootsie', 1982, 50000, 16),
  ('Tieta', 1995, 200000, 18);


INSERT INTO Personagem
  (codA, codF, personagem, cache)
VALUES
  (1, 1, 'Mary', 3000),
  (1, 2, 'Sandy', 5000),
  (2, 3, 'John', 5000),
  (3, 4, 'Mary', 1000),
  (4, 4, 'Tootsie', 2000),
  (5, 5, 'Tieta', 500);