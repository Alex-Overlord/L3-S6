$.ajax({
   url : 'bdd.php', // my php file
   type : 'GET', // type of the HTTP request
   success : function(result){ 
      var data = jQuery.parseJSON(result);
      var langueM = data[0];
      console.log("LangueM : "+langueM);

      var statut = data[1];
      console.log("Statut : "+statut);

      var secteur = data[2];
      console.log("Secteur : "+secteur);

      var email = data[3];
      console.log("Email : "+email);
   }
});