$.ajax({
   url : 'data.php', // my php file
   type : 'GET', // type of the HTTP request
   success : function(result){ 
      var data = jQuery.parseJSON(result);

      var langueM_val = data[0][0];
      console.log("LangueM : "+langueM_val);

      var statut_val = data[1][0];
      console.log("Statut : "+statut_val);

      var secteur_val = data[2][0];
      console.log("Secteur : "+secteur_val);

      var email_val = data[3][0];
      console.log("Email : "+email_val);

      
      var o1 = data[4][0];
      console.log("o1 : "+o1);

      var p1 = data[5][0];
      console.log("p1 : "+p1);

      var n1 = data[6][0];
      console.log("n1 : "+n1);

      
      var o2 = data[7][0];
      console.log("o2 : "+o2);

      var p2 = data[8][0];
      console.log("p2 : "+p2);

      var n2 = data[9][0];
      console.log("n2 : "+n2);


      var o3 = data[10][0];
      console.log("o3 : "+o3);

      var p3 = data[11][0];
      console.log("p3 : "+p3);

      var n3 = data[12][0];
      console.log("n3 : "+n3);


      var o4 = data[13][0];
      console.log("o4 : "+o4);

      var p4 = data[14][0];
      console.log("p4 : "+p4);

      var n4 = data[15][0];
      console.log("n4 : "+n4);

      
      var t0 = data[16][0];
      console.log("t0 : "+t0);

      var t1 = data[17][0];
      console.log("t1 : "+t1);

      var t2 = data[18][0];
      console.log("t2 : "+t2);

      var t3 = data[19][0];
      console.log("t3 : "+t3);

      var t4 = data[20][0];
      console.log("t4 : "+t4);


      var nb = data[21][0];
      console.log("nb : "+nb);

      
      var moy = data[22][0];
      console.log("moy : "+moy);

      
      var tOrdreQ = data[23][0];
      console.log("tOrdreQ : "+tOrdreQ);

      var tOrdreR = data[24][0];
      console.log("tOrdreR : "+tOrdreR);


      // LangueM
      let langueM = new Chart(document.getElementById('langueM').getContext('2d'), {
        type: 'pie',
        data: {
          datasets: [{
            data: langueM_val,
            backgroundColor: ['green','red']
          }],
          labels: ['OUI', 'NON']
        },
        options: {
          responsive: true,
          legend: {
            position: 'bottom',
            verticalAlign:'middle'
          },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          }
        }
      })

      // Statut
      let statut = new Chart(document.getElementById('statut').getContext('2d'), {
        type: 'pie',
        data: {
          datasets: [{
            data: statut_val,
            backgroundColor: ['orange','grey','blue']
          }],
          labels: ['ÉTUDIANT', 'ENSEIGNANT', 'AUTRE']
        },
        options: {
          responsive: true,
          legend: {
            position: 'bottom',
            verticalAlign:'middle'
          },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          }
        }
      })

      // Secteur
      let secteur = new Chart(document.getElementById('secteur').getContext('2d'), {
        type: 'pie',
        data: {
          datasets: [{
            data: secteur_val,
            backgroundColor: ['blue','orange','red','black','green','purple','maroon','grey']
          }],
          labels: ['ART', 'DROIT ET SCIENCE POLITIQUE', 'ÉCONOMIE ET GESTION', 'LETTRES ET LANGUES', 'SANTÉ', 'SCIENCES APPLIQUÉES', 'SCIENCES HUMAINES ET SOCIALES', 'AUTRE']
        },
        options: {
          responsive: true,
          legend: {
            position: 'left',
            verticalAlign:'middle'
          },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          }
        }
      })

      // Email
      /*let email = new Chart(document.getElementById('email').getContext('2d'), {
        type: 'pie',
        data: {
          datasets: [{
            data: email_val,
            backgroundColor: ['green','red']
          }],
          labels: ['OUI', 'NON']
        },
        options: {
          responsive: true,
          legend: {
            position: 'bottom',
            verticalAlign:'middle'
          },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          }
        }
      })*/

      Chart.defaults.groupableBar = Chart.helpers.clone(Chart.defaults.bar);

      var helpers = Chart.helpers;
      Chart.controllers.groupableBar = Chart.controllers.bar.extend({
        calculateBarX: function (index, datasetIndex) {
          // position the bars based on the stack index
          var stackIndex = this.getMeta().stackIndex;
          return Chart.controllers.bar.prototype.calculateBarX.apply(this, [index, stackIndex]);
        },

        hideOtherStacks: function (datasetIndex) {
          var meta = this.getMeta();
          var stackIndex = meta.stackIndex;

          this.hiddens = [];
          for (var i = 0; i < datasetIndex; i++) {
            var dsMeta = this.chart.getDatasetMeta(i);
            if (dsMeta.stackIndex !== stackIndex) {
              this.hiddens.push(dsMeta.hidden);
              dsMeta.hidden = true;
            }
          }
        },

        unhideOtherStacks: function (datasetIndex) {
          var meta = this.getMeta();
          var stackIndex = meta.stackIndex;

          for (var i = 0; i < datasetIndex; i++) {
            var dsMeta = this.chart.getDatasetMeta(i);
            if (dsMeta.stackIndex !== stackIndex) {
              dsMeta.hidden = this.hiddens.unshift();
            }
          }
        },

        calculateBarY: function (index, datasetIndex) {
          this.hideOtherStacks(datasetIndex);
          var barY = Chart.controllers.bar.prototype.calculateBarY.apply(this, [index, datasetIndex]);
          this.unhideOtherStacks(datasetIndex);
          return barY;
        },

        calculateBarBase: function (datasetIndex, index) {
          this.hideOtherStacks(datasetIndex);
          var barBase = Chart.controllers.bar.prototype.calculateBarBase.apply(this, [datasetIndex, index]);
          this.unhideOtherStacks(datasetIndex);
          return barBase;
        },

        getBarCount: function () {
          var stacks = [];

          // put the stack index in the dataset meta
          Chart.helpers.each(this.chart.data.datasets, function (dataset, datasetIndex) {
            var meta = this.chart.getDatasetMeta(datasetIndex);
            if (meta.bar && this.chart.isDatasetVisible(datasetIndex)) {
              var stackIndex = stacks.indexOf(dataset.stack);
              if (stackIndex === -1) {
                stackIndex = stacks.length;
                stacks.push(dataset.stack);
              }
              meta.stackIndex = stackIndex;
            }
          }, this);

          this.getMeta().stacks = stacks;
          return stacks.length;
        },
      });

      var data = {
        labels: ["P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10", "P11", "P12"],
        datasets: [
          {
            label: "OUI",
            backgroundColor: 'green',
            data: o1,
            stack: 1
          },
          {
            label: "PEUT-ÊTRE",
            backgroundColor: 'blue',
            data: p1,
            stack: 1
          },
          {
            label: "NON",
            backgroundColor: "red",
            data: n1,
            stack: 1
          },



          {
            label: "OUI",
            backgroundColor: 'green',
            data: o2,
            stack: 2
          },
          {
            label: "PEUT-ÊTRE",
            backgroundColor: 'blue',
            data: p2,
            stack: 2
          },
          {
            label: "NON",
            backgroundColor: "red",
            data: n2,
            stack: 2
          },



          {
            label: "OUI",
            backgroundColor: 'green',
            data: o3,
            stack: 3
          },
          {
            label: "PEUT-ÊTRE",
            backgroundColor: 'blue',
            data: p3,
            stack: 3
          },
          {
            label: "NON",
            backgroundColor: "red",
            data: n3,
            stack: 3
          },



          {
            label: "OUI",
            backgroundColor: 'green',
            data: o4,
            stack: 4
          },
          {
            label: "PEUT-ÊTRE",
            backgroundColor: 'blue',
            data: p4,
            stack: 4
          },
          {
            label: "NON",
            backgroundColor: "red",
            data: n4,
            stack: 4
          },
        ]
      };

      // Réponses
      var reponses = document.getElementById("reponses").getContext("2d");
      new Chart(reponses, {
        type: 'groupableBar',
        data: data,
        options: {
          responsive: true,
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              font: {
                weight: 'bold',
                size: '12'
              }
            }
          },
          legend: {
            onClick: (e) => e.stopPropagation(),
            labels: {
              generateLabels: function(chart) {
                return Chart.defaults.global.legend.labels.generateLabels.apply(this, [chart]).filter(function(item, i){
                    return i <= 2;
                });
              }
            }
          },
          scales: {
            yAxes: [{
              stacked: true
            }]
          }
        }
      });

      // Temps moyen de réponse
      let tempsQ = new Chart(document.getElementById("tempsQ").getContext("2d"), {
        type: "horizontalBar",
        data: {
          labels: ["P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10", "P11", "P12"],
          datasets: [
            {
                backgroundColor: 'black',
                label: "LECTURE DE LA QUESTION",
                data: t0
            },
            {
                backgroundColor: 'orange',
                label: "REPONSE 1",
                data: t1
            },
            {
                backgroundColor: 'brown',
                label: "REPONSE 2",
                data: t2
            },
            {
                backgroundColor: 'grey',
                label: "REPONSE 3",
                data: t3
            },
            {
                backgroundColor: 'purple',
                label: "REPONSE 4",
                data: t4
            }
          ]
        },
        options: {
          responsive: true,
          legend: {
            position: 'bottom'
          },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              position: 'top',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          },
          scales: {
            xAxes:[{
              stacked: true
            }],
            yAxes:[{
              stacked: true
            }],
          }
        }
      });

      // Nombre de réponses par sens
      let nbSens = new Chart(document.getElementById('nbSens').getContext('2d'), {
        type: 'pie',
        data: {
          datasets: [{
            data: nb,
            backgroundColor: ['green','blue','red']
          }],
          labels: ["OUI", "PEUT-ÊTRE", "NON"]
        },
        options: {
          responsive: true,
          legend: {
            position: 'bottom',
            verticalAlign:'middle'
          },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          }
        }
      })
      
      // Temps par type de réponse
      let tempsQ2 = new Chart(document.getElementById('tempsQ2').getContext('2d'), {
        type: 'bar',
        data: {
          labels: ["OUI", "PEUT-ÊTRE", "NON"],
          datasets: [
            {
              backgroundColor: ["green", "blue","red"],
              data: moy
            }
          ]
        },
        options: {
          legend: { display: false },
          plugins: {
            datalabels: {
              color: '#fff',
              anchor: 'center',
              position: 'top',
              font: {
                weight: 'bold',
                size: '17'
              }
            }
          },
          scales: {
            yAxes: [{
                display: true,
                ticks: {
                    beginAtZero: true
                }
            }]
          }
        }
      });

      // Temps par ordre de réponse
      let tempsOrdre = new Chart(document.getElementById('tempsOrdre').getContext('2d'), {
        type: 'line',
        data: {
          labels: ["1","2","3","4","5","6","7","8","9","10","11","12"],
          datasets: [{
            label: "LECTURE DE LA QUESTION",
            backgroundColor: 'black',
            borderColor: 'black',
            data: tOrdreQ,
            fill: false
          }, {
            label: "TEMPS DE REPONSE MOYEN PAR PROPOSITION",
            backgroundColor: 'orange',
            borderColor: 'orange',
            data: tOrdreR,
            fill: false
          }]
        },
        options: {
          legend: { position:'bottom' },
          scales: {
            yAxes: [{
                display: true,
                ticks: {
                    beginAtZero: true
                }
            }]
          },
          plugins: {
            datalabels: {
                display: false
            }
          }
        }
      });
   }
});