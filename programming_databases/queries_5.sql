-- 1
CREATE TABLE empregado 
(
id INT AUTO_INCREMENT,
nome VARCHAR(255),
salario FLOAT,

PRIMARY KEY (id)
);


-- 2
DROP PROCEDURE IF EXISTS insere10;

DELIMITER $$

CREATE PROCEDURE insere10(IN nome VARCHAR(255))
  BEGIN
  
    DECLARE i INT DEFAULT 1;
    
    myLoop: LOOP 
      
      INSERT INTO empregado
        (nome, salario)
      VALUES
        (CONCAT(nome, i), 1000 + (i * 42));
      
      IF i = 10 THEN
        LEAVE myLoop;
      END IF;
      
      SET i = i + 1;
      
    END LOOP myLoop;
  
  END $$

DELIMITER ;


-- 3
DROP PROCEDURE IF EXISTS countEmployees;

DELIMITER $$

CREATE PROCEDURE countEmployees()
  BEGIN
  
  SELECT 
    COUNT(*) AS EmployeesNumber
  FROM 
    empregado;
  
  END $$
  
DELIMITER ;


mysqldump --user=robert --password --lock-tables --verbose --databases Hospital > hospital.sql