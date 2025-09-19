var belo_horizonte_rio_de_janeiro >= 0;
var belo_horizonte_sao_paulo >= 0;
var ribeirao_preto_rio_de_janeiro >= 0;
var ribeirao_preto_sao_paulo >= 0;
var sao_jose_dos_campos_rio_de_janeiro >= 0;
var sao_jose_dos_campos_sao_paulo >= 0;


minimize Cost:
  13 * belo_horizonte_rio_de_janeiro + 
  25 * belo_horizonte_sao_paulo +
  25 * ribeirao_preto_rio_de_janeiro +
  16 * ribeirao_preto_sao_paulo +
  15 * sao_jose_dos_campos_rio_de_janeiro +
  40 * sao_jose_dos_campos_sao_paulo;


subject to RioDeJaneiroConsume:
  belo_horizonte_rio_de_janeiro + 
  ribeirao_preto_rio_de_janeiro + 
  sao_jose_dos_campos_rio_de_janeiro = 180;

subject to SaoPauloConsume:
  belo_horizonte_sao_paulo + 
  ribeirao_preto_sao_paulo + 
  sao_jose_dos_campos_sao_paulo = 140;

subject to BeloHorizonteSupply:
  belo_horizonte_rio_de_janeiro + 
  belo_horizonte_sao_paulo <= 70;

subject to RibeiraoPretoSupply:
  ribeirao_preto_rio_de_janeiro + 
  ribeirao_preto_sao_paulo <= 130;

subject to SaoJoseDosCamposSupply:
  sao_jose_dos_campos_rio_de_janeiro + 
  sao_jose_dos_campos_sao_paulo <= 120;