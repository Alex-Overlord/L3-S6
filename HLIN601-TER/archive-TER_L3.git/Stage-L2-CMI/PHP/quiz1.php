<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"> 
    <link rel="stylesheet" href="">
    <title>Questionnaires pour l'études des préférences de phrases</title>  
</head>
<body>	
<h1>Questionnaire 1</h1>
   
     <?php
     $Q='Q1';
     $deb=microtime();
     include("questionExistence.php");
      if($_POST[$Q]) 
     echo "BONJOUR";
     ?>
     
</br>
<FORM ACTION="quiz2.php">
    <INPUT TYPE="SUBMIT" VALUE="  Suivant  ">
  </FORM>

  
    
    
   


</body>
</html>