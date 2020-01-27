<?php
  try{
      $dbh = new PDO('mysql:host=192.168.0.20:3307;dbname=TERL3','jroux', '1234');
      $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

  }
  catch(PDOException $e){
      echo $e->getMessage();
      die("Connexion impossible !");
  }
?>