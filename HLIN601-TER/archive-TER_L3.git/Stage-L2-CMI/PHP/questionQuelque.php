

<?php
     
    
   exec("/usr/bin/python3 /auto_home/ysmaili/Bureau/Stage-L2-CMI/Generation/quelques.py");
      if (!$fp = fopen("quelques.txt", "r")){
      echo "echec d'ouveture du fichier";
        
      exit;
      }

      else {
         $n = 1;
      while ($n<=4) {
        if ($n == 1 ){
          $ligne = fgets ($fp,255);
          echo $ligne;
          $n = 2;
        }else{
        $o = '<p class="ratingButtons">' . "\n";
         
       $ligne = fgets ($fp,255);
        
        
        $o.= '<input type="radio" class="spacing" name= $Q"'. '" value="' . $ligne. '"' .'>' . $ligne . "\n";
       // echo "<input type="radio" name="Q1" value="$ligne"> ";
       //$Fichier .= $ligne;
       echo $o ;
       $n++;

      }
    }
      fclose($fp);
      }
      
     ?>  