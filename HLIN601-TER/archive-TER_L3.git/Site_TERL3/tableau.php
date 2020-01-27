<?php
// estVide()
function estVide($champ){
  if($champ == ""){
    return "non";
  }
  else{
    return "oui";
  }
}

// point()
function pointGrand($x){
  if($x == "oui" || $x == "o"){
    return "<span class='pointGrand point-vert'></span>";
  }
  else if($x == "non" || $x == "n"){
    return "<span class='pointGrand point-rouge'></span>";
  }
  else{
    return "<span class='pointGrand point-bleu'></span>";
  }
}

// point()
function point($x){
  if($x == "oui" || $x == "o"){
    return "<span class='point point-vert'></span>";
  }
  else if($x == "non" || $x == "n"){
    return "<span class='point point-rouge'></span>";
  }
  else{
    return "<span class='point point-bleu'></span>";
  }
}

// PDO
try{
  $dbh = new PDO('mysql:host=192.168.0.20:3307;dbname=TERL3','jroux', '1234');
  $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

}
catch(PDOException $e){
  echo $e->getMessage();
  die("Connexion impossible !"); 
}

// Tableau
$tableau = $dbh->query("SELECT id,dateEnvoi,langueM,statut,secteur,email,1_1 AS q1_1,1_2 AS q1_2,1_3 AS q1_3,2_1 AS q2_1,2_2 AS q2_2,2_3 AS q2_3,3_1 AS q3_1,3_2 AS q3_2,4_1 AS q4_1,4_2 AS q4_2,4_3 AS q4_3,5_1 AS q5_1,5_2 AS q5_2,5_3 AS q5_3,6_1 AS q6_1,6_2 AS q6_2,7_1 AS q7_1,7_2 AS q7_2,7_3 AS q7_3,8_1 AS q8_1,8_2 AS q8_2,9_1 AS q9_1,9_2 AS q9_2,9_3 AS q9_3,10_1 AS q10_1,10_2 AS q10_2,10_3 AS q10_3,10_4 AS q10_4,11_1 AS q11_1,11_2 AS q11_2,12_1 AS q12_1,12_2 AS q12_2,12_3 AS q12_3 FROM utilisateur ORDER BY id");
$table_tableau = $tableau->fetchAll(PDO::FETCH_OBJ);
for ($i=count($table_tableau)-1; $i>=0; $i--){
  echo "<tr>";
  echo "<th scope='row'>".($i+1)."</th>";
  echo "<td>".$table_tableau[$i]->dateEnvoi."</td>";
  echo "<td>".pointGrand($table_tableau[$i]->langueM)."</td>";
  echo "<td>".$table_tableau[$i]->statut."</td>";
  echo "<td>".$table_tableau[$i]->secteur."</td>";
  //echo "<td>".pointGrand(estVide($table_tableau[$i]->email))."</td>";
  echo "<td>".point($table_tableau[$i]->q1_1).point($table_tableau[$i]->q1_2).point($table_tableau[$i]->q1_3)."</td>";
  echo "<td>".point($table_tableau[$i]->q2_1).point($table_tableau[$i]->q2_2).point($table_tableau[$i]->q2_3)."</td>";
  echo "<td>".point($table_tableau[$i]->q3_1).point($table_tableau[$i]->q3_2)."</td>";
  echo "<td>".point($table_tableau[$i]->q4_1).point($table_tableau[$i]->q4_2).point($table_tableau[$i]->q4_3)."</td>";
  echo "<td>".point($table_tableau[$i]->q5_1).point($table_tableau[$i]->q5_2).point($table_tableau[$i]->q5_3)."</td>";
  echo "<td>".point($table_tableau[$i]->q6_1).point($table_tableau[$i]->q6_2)."</td>";
  echo "<td>".point($table_tableau[$i]->q7_1).point($table_tableau[$i]->q7_2).point($table_tableau[$i]->q7_3)."</td>";
  echo "<td>".point($table_tableau[$i]->q8_1).point($table_tableau[$i]->q8_2)."</td>";
  echo "<td>".point($table_tableau[$i]->q9_1).point($table_tableau[$i]->q9_2).point($table_tableau[$i]->q9_3)."</td>";
  echo "<td>".point($table_tableau[$i]->q10_1).point($table_tableau[$i]->q10_2).point($table_tableau[$i]->q10_3).point($table_tableau[$i]->q10_4)."</td>";
  echo "<td>".point($table_tableau[$i]->q11_1).point($table_tableau[$i]->q11_2)."</td>";
  echo "<td>".point($table_tableau[$i]->q12_1).point($table_tableau[$i]->q12_2).point($table_tableau[$i]->q12_3)."</td>";
  echo "</tr>";
}
?>