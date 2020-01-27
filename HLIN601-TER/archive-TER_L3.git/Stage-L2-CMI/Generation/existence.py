import random

#################################
#               REPONSES


i=1
while i<2:   
    articleM = ['un', 'le']
    articleF = ['une', 'la']
    articlePl =['des' , 'les']
    article = [articleF, articleM, articlePl]
    choixArticleInter = random.choice(article)
    choixArticle = random.choice (choixArticleInter)
    
    
    
    sujetM=['vigil', 'policier', 'pompier', 'hibou', 'pou', 'corail', 'chacal', 'enseignant']
    sujetF=['vigile', 'policière', 'enseignante', 'chouette', 'gardienne', 'joueuse', 'poule', 'personne']
    sujet = [sujetF , sujetM]
    
#gestion des accords avec le "l'"
    if choixArticleInter == articleF :
        choixSujet = random.choice(sujetF)
        if ((choixSujet[:1] == 'a'
        or choixSujet[:1] == 'e'
        or choixSujet[:1] == 'i' 
        or choixSujet[:1] == 'o' 
        or choixSujet[:1] == 'u'
        or choixSujet[:1] == 'y') 
        and choixArticle == 'la') :
            choixArticle = "l'"                
    
    elif choixArticleInter == articleM :
        choixSujet = random.choice(sujetM)
        if ((choixSujet[:1] == 'a'
        or choixSujet[:1] == 'e'
        or choixSujet[:1] == 'i' 
        or choixSujet[:1] == 'o' 
        or choixSujet[:1] == 'u'
        or choixSujet[:1] == 'y') 
        and choixArticle == 'le') :
            choixArticle = "l'"

    #gestions des exceptions au pluriel
    else :
        choixSujetInter = random.choice(random.choice(sujet))
        if (choixSujetInter[-2:] == 'au' 
        or choixSujetInter[-2:] == 'eu' 
        or choixSujetInter[-3:] == 'eau' ):
            
            if (choixSujetInter == 'bleu' 
            or choixSujetInter == 'pneu'
            or choixSujetInter == 'landau') :
                choixSujetInter = choixSujetInter+'s'
            else :
                choixSujetInter = choixSujetInter+'x'
                
        elif (choixSujetInter == 'hibou' 
        or choixSujetInter == 'bijou' 
        or choixSujetInter == 'chou' 
        or choixSujetInter =='caillou' 
        or choixSujetInter =='genou' 
        or choixSujetInter == 'pou' 
        or choixSujetInter == 'joujou') :
            choixSujetInter = choixSujetInter+'x'
        
        elif (choixSujetInter[-1:] == 'x' 
        or choixSujetInter[-1:] == 'z' 
        or choixSujetInter[-1:] == 's'):
            choixSujetInter = choixSujetInter
        
        elif choixSujetInter[-2:] == 'al' :
            if (choixSujetInter == 'festival' 
            or choixSujetInter == 'chacal'
            or choixSujetInter == 'carnaval'
            or choixSujetInter == 'récital'
            or choixSujetInter == 'bal' ):
                choixSujetInter = choixSujetInter+'s'
            else :
                choixSujetInter = choixSujetInter[:-1]+'ux'
        
        elif choixSujetInter[-3:] == 'ail':
            if (choixSujetInter == 'corail' 
            or choixSujetInter == 'travail'
            or choixSujetInter == 'vitrail'
            or choixSujetInter == 'bail' ):
                choixSujetInter = choixSujetInter[:-2]+'ux'
            else :
                choixSujetInter = choixSujetInter[-1:]+'s'
            
        elif choixSujetInter == 'monsieur' :
            choixSujetInter = 'messires'
        
        elif choixSujetInter == 'oeil' :
            choixSujetInter = 'yeux'
            
        else :    
            choixSujetInter = choixSujetInter+'s'
            
        choixSujet = choixSujetInter
        

    
    
    CODTemps = ['matin', 'midi', 'soir', 'weekend', 'lundi', 'mardi', 'mercredi', 'jeudi', 'vendredi',
                'samedi', 'dimanche', 'hiver', 'automne', 'été', 'printemps']    

    COD2F = ['porte', 'gare', 'rue', 'avenue', 'entrée', 'place', 'sortie' ]        
    COD2M = ['sapin', 'coffre', 'musée','anneau', 'bateau', 'hibou','monsieur', 
             'bijou', 'joujou', 'chou', 'cheval']   

    COD2 = [COD2F, COD2M]
    
    COD3= ['corail', 'cheval', 'chameau', 'vitrail', 'bail', 'oeil']
    CODAliment= ['fruit', 'légume', 'plat', 'agneau', 'cheval', 'poisson', 'viande', 'melon']
    
    quantificateursM = ['chaque', 'tout', 'tous les']
    quantificateursF = ['chaque', 'toute', 'toutes les']

    

    verbe = [['se lèver', [CODTemps]], ['se préparer', [CODTemps]], ['aider', [CODTemps]], ['espèrer', [CODTemps]],
             ['rentrer', [CODTemps]], ['essayer', [CODTemps]], ['prier', [CODTemps]], ['rentrer', [CODTemps]],
             ['répèter', [CODTemps]], ['glisser', [CODTemps]], ['jouer', [CODTemps]], ['rêver', [CODTemps]], 
             ['voyager', [CODTemps]], ['garder',[COD2]], ['manger', [CODTemps,CODAliment]], ['chanter', [CODTemps]], 
             ['finir', [COD3]], ['choisir', COD3], ['prendre', [CODAliment]], ['apprendre', [CODTemps]], ['entreprendre', [CODTemps]],
             ['peindre', [CODTemps]], ['atteindre', [COD2]], ['restreindre', [COD2]], ['prévoir', [CODTemps]], ['voir', [COD3]],
             ['moudre', [CODTemps]], ['pouvoir', [CODTemps]], ['valoir', [COD3]], ['vouloir', [CODAliment]], ['mettre', [CODTemps]],
             ['permettre', [CODTemps]],['préparer', [CODAliment]] ]
    
    choixInterVerbe =  random.choice(verbe) #renvoie une liste avec un verbe et ses cod possibles    

    if choixArticleInter == articleF :
        if choixInterVerbe[0][-2:] == 'er' :
            choixVerbe = choixInterVerbe[0][:-1]
        elif (choixInterVerbe[0][-2:] == 'ir' and choixInterVerbe[0][-3:] != 'oir') :
            choixVerbe = choixInterVerbe[0][:-1]+'t'
#gestion de quelques verbes du 3ème groupe               
        elif choixInterVerbe[0][-5:] == 'endre' :
            choixVerbe = choixInterVerbe[0][:-2]
        elif (choixInterVerbe[0][-6:] == 'eindre'  or choixInterVerbe[0][-6:] == 'aindre'):
            choixVerbe = choixInterVerbe[0][:-3]+'t'  
        elif ((choixInterVerbe[0][-3:] == 'oir' or choixInterVerbe[0][-4:] == 'oire')
              and (choixInterVerbe[0] != 'pouvoir' and choixInterVerbe[0] != 'vouloir' and choixInterVerbe[0] != 'valoir' )) :
            choixVerbe = choixInterVerbe[0][:-1]+'t'
        elif choixInterVerbe[0][-5:] == 'oudre':
            choixVerbe = choixInterVerbe[0][:-2]
        elif (choixInterVerbe[0] == 'pouvoir' or choixInterVerbe[0] == 'vouloir') :
            choixVerbe = choixInterVerbe[0][:-6]+'eut' 
        elif choixInterVerbe[0] == 'valoir' :            
            choixVerbe = choixInterVerbe[0][:-5]+'aut'
        elif choixInterVerbe[0][-3:] == 'tre' :
            choixVerbe = choixInterVerbe[0][:-3]    
   
    elif choixArticleInter == articleM :
        if choixInterVerbe[0][-2:] == 'er' :
            choixVerbe = choixInterVerbe[0][:-1]
        elif (choixInterVerbe[0][-2:] == 'ir' and choixInterVerbe[0][-3:] != 'oir'): 
            choixVerbe = choixInterVerbe[0][:-1]+'t'
#gestion de quelques verbes du 3ème groupe            
        elif choixInterVerbe[0][-5:] == 'endre' :
            choixVerbe = choixInterVerbe[0][:-2]
        elif (choixInterVerbe[0][-6:] == 'eindre' or choixInterVerbe[0][-6:] == 'aindre'):
            choixVerbe = choixInterVerbe[0][:-3]+'t' 
        elif ((choixInterVerbe[0][-3:] == 'oir' or choixInterVerbe[0][-4:] == 'oire')
              and (choixInterVerbe[0] != 'pouvoir' and choixInterVerbe[0] != 'vouloir' and choixInterVerbe[0] != 'valoir' )) :
            choixVerbe = choixInterVerbe[0][:-1]+'t'    
        elif choixInterVerbe[0][-5:] == 'oudre':
            choixVerbe = choixInterVerbe[0][:-2]     
        elif (choixInterVerbe[0] == 'pouvoir' or choixInterVerbe[0] == 'vouloir') :
            choixVerbe = choixInterVerbe[0][:-6]+'eut' 
        elif choixInterVerbe[0] == 'valoir' :            
            choixVerbe = choixInterVerbe[0][:-5]+'aut'               
        elif choixInterVerbe[0][-3:] == 'tre' :
            choixVerbe = choixInterVerbe[0][:-3] 
    
    else :
        if choixInterVerbe[0][-2:] == 'er' :
            choixVerbe = choixInterVerbe[0][:-1]+'nt'
        elif (choixInterVerbe[0][-2:] == 'ir' and choixInterVerbe[0][-3:] != 'oir'): 
            choixVerbe = choixInterVerbe[0][:-1]+'ssent'
#gestion de quelques verbes du 3ème groupe   
        elif choixInterVerbe[0][-5:] == 'endre' :
            choixVerbe = choixInterVerbe[0][:-3]+'nent'
        elif (choixInterVerbe[0][-6:] == 'eindre'  or choixInterVerbe[0][-6:] == 'aindre'):
            choixVerbe = choixInterVerbe[0][:-4]+'gnent'       
        elif ((choixInterVerbe[0][-3:] == 'oir' or choixInterVerbe[0][-4:] == 'oire')
              and (choixInterVerbe[0] != 'pouvoir' and choixInterVerbe[0] != 'vouloir' and choixInterVerbe[0] != 'valoir' )) :
            choixVerbe = choixInterVerbe[0][:-1]+'ent'
        elif choixInterVerbe[0][-5:] == 'oudre':
            choixVerbe = choixInterVerbe[0][:-3]+'lent'        
        elif choixInterVerbe[0] == 'pouvoir' :
            choixVerbe = choixInterVerbe[0][:-6]+'euvent' 
        elif choixInterVerbe[0] == 'valoir' :  
            choixVerbe = choixInterVerbe[0][:-4]+'lent'    
        elif choixInterVerbe[0] == 'vouloir' :
            choixVerbe = choixInterVerbe[0][:-6]+'eulent' 
        elif choixInterVerbe[0][-3:] == 'tre' :
            choixVerbe = choixInterVerbe[0][:-2]+'ent' 
    
    del(choixInterVerbe[0])
    
    complementPhrase =''
    #choix liste COD
    complementPhraseInter = random.choice(choixInterVerbe[0])

    choixInterVerbe =random.choice(choixInterVerbe)

    
    if complementPhraseInter == COD2 :
        complementPhraseInter = random.choice(COD2)
        if complementPhraseInter == COD2F :                        #vérifie le genre    
            complementPhrase = random.choice(COD2F)
            choix1 = quantificateursF[0]
            choix2 = quantificateursF[1]
            choix3 = quantificateursF[2]

        else :
            complementPhrase = random.choice(COD2M)
            choix1 = quantificateursM[0]
            choix2 = quantificateursM[1]
            choix3 = quantificateursM[2]

    elif complementPhraseInter == CODTemps :
        choix1 = quantificateursM[0]
        choix2 = quantificateursM[1]
        choix3 = quantificateursM[2]
        complementPhrase = random.choice(CODTemps)

    elif complementPhraseInter == CODAliment :
        choix1 = quantificateursM[0]
        choix2 = quantificateursM[1]
        choix3 = quantificateursM[2]
        complementPhrase = random.choice(CODAliment) 

    else :
        choix1 = quantificateursM[0]
        choix2 = quantificateursM[1]
        choix3 = quantificateursM[2]
        complementPhrase = random.choice(COD3) 


    complementPhrasePluriel = complementPhrase
    
    #GESTION PLURIEL DU COD
    
    if (choix3 == 'tous les' or choix3 =='toutes les') :
        if (complementPhrasePluriel[-2:] == 'au' 
        or complementPhrasePluriel[-2:] == 'eu' 
        or complementPhrasePluriel[-3:] == 'eau' ):
            
            if (complementPhrasePluriel == 'bleu' 
            or complementPhrasePluriel == 'pneu'
            or complementPhrasePluriel == 'landau') :
                complementPhrasePluriel = complementPhrasePluriel+'s'
            else :
                complementPhrasePluriel = complementPhrasePluriel+'x'
                
        elif (complementPhrasePluriel == 'hibou' 
        or complementPhrasePluriel == 'bijou' 
        or complementPhrasePluriel == 'chou' 
        or complementPhrasePluriel =='caillou' 
        or complementPhrasePluriel =='genou' 
        or complementPhrasePluriel == 'pou' 
        or complementPhrasePluriel == 'joujou') :
            complementPhrasePluriel = complementPhrasePluriel+'x'
        
        elif (complementPhrasePluriel[-1:] == 'x' 
        or complementPhrasePluriel[-1:] == 'z' 
        or complementPhrasePluriel[-1:] == 's'):
            complementPhrasePluriel = complementPhrasePluriel
        
        elif complementPhrasePluriel[-2:] == 'al' :
            if (complementPhrasePluriel == 'festival' 
            or complementPhrasePluriel == 'chacal'
            or complementPhrasePluriel == 'carnaval'
            or complementPhrasePluriel == 'récital'
            or complementPhrasePluriel == 'bal' ):
                complementPhrasePluriel = complementPhrasePluriel+'s'
            else :
                complementPhrasePluriel = complementPhrasePluriel[:-1]+'ux'
        
        elif complementPhrasePluriel[-3:] == 'ail':
            if (complementPhrasePluriel == 'corail' 
            or complementPhrasePluriel == 'travail'
            or complementPhrasePluriel == 'vitrail'
            or complementPhrasePluriel == 'bail' ):
                complementPhrasePluriel = complementPhrasePluriel[:-2]+'ux'
            else :
                complementPhrasePluriel = complementPhrasePluriel[-1:]+'s'
            
        elif complementPhrasePluriel == 'monsieur' :
            complementPhrasePluriel = 'messires'
        
        elif complementPhrasePluriel == 'oeil' :
            complementPhrasePluriel = 'yeux'
            
        else :    
            complementPhrasePluriel = complementPhrasePluriel+'s'
    
    finPhrase = 'peut se lire'
    finPhrase2 = 'signifie que'
    chance = random.randrange(1,3,1)
    chance2 = random.randrange(1,3,1)
    fichier= open('existence.txt','w')
    if chance == 1:
        if chance2 ==1 :
            if choixArticle == "l'" : 
                n1 = '\n'
                phrases = ['La phrase :'+'     '+choixArticle+choixSujet+' '+choixVerbe+' '+'les'+' '+complementPhrasePluriel+' '+finPhrase, n1,
                           choixArticle+choixSujet+' '+choixVerbe+' '+choix1+' '+complementPhrase, n1,
                           choixArticle+choixSujet+' '+choixVerbe+' '+choix2+' '+complementPhrase, n1,
                           choixArticle+choixSujet+' '+choixVerbe+' '+choix3+' '+complementPhrase]
                print('La phrase :','     '+choixArticle+choixSujet, choixVerbe, 'les', complementPhrasePluriel, finPhrase)
                print(choixArticle+choixSujet, choixVerbe, choix1 , complementPhrase)
                print(choixArticle+choixSujet, choixVerbe, choix2 , complementPhrase)
                print(choixArticle+choixSujet, choixVerbe, choix3 , complementPhrasePluriel)
                fichier.writelines(phrases)
            else :
                print('La phrase :','     '+choixArticle, choixSujet, choixVerbe, 'les', complementPhrasePluriel, finPhrase)
                print(choixArticle, choixSujet, choixVerbe, choix1 , complementPhrase)
                print(choixArticle, choixSujet, choixVerbe, choix2 , complementPhrase)
                print(choixArticle, choixSujet, choixVerbe, choix3 , complementPhrasePluriel)
                n1 = '\n'
                phrases = ['La phrase :'+'     '+choixArticle+' '+choixSujet+' '+choixVerbe+' '+'les'+' '+complementPhrasePluriel+' '+finPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix1+' '+complementPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix2+' '+complementPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix3+' '+complementPhrasePluriel]
                fichier.writelines(phrases)
        else :
            if choixArticle == "l'" :    
                print('La phrase :','     '+choixArticle+choixSujet, choixVerbe, 'les', complementPhrasePluriel, finPhrase2)
                print(choixArticle+choixSujet, choixVerbe, choix1 , complementPhrase)
                print(choixArticle+choixSujet, choixVerbe, choix2 , complementPhrase)
                print(choixArticle+choixSujet, choixVerbe, choix3 , complementPhrasePluriel)
                n1 = '\n'
                phrases = ['La phrase :'+'     '+choixArticle+' '+choixSujet+' '+choixVerbe+' '+'les'+' '+complementPhrasePluriel+' '+finPhrase2, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix1+' '+complementPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix2+' '+complementPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix3+' '+complementPhrasePluriel]
                fichier.writelines(phrases)
            else :
                print('La phrase :','     '+choixArticle, choixSujet, choixVerbe, 'les', complementPhrasePluriel, finPhrase2)
                print(choixArticle, choixSujet, choixVerbe, choix1 , complementPhrase)
                print(choixArticle, choixSujet, choixVerbe, choix2 , complementPhrase)
                print(choixArticle, choixSujet, choixVerbe, choix3 , complementPhrasePluriel)
                n1 = '\n'
                phrases = ['La phrase :'+'     '+choixArticle+' '+choixSujet+' '+choixVerbe+' '+'les'+' '+complementPhrasePluriel+' '+finPhrase2, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix1+' '+complementPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix2+' '+complementPhrase, n1,
                           choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix3+' '+complementPhrasePluriel]
                fichier.writelines(phrases)
    else :
        if chance2 == 1 :
            print('La phrase :',"Il y'a "+choixArticle, choixSujet,'qui', choixVerbe, 'les', complementPhrasePluriel, finPhrase)
            print(choixArticle, choixSujet, choixVerbe, choix1 , complementPhrase)
            print(choixArticle, choixSujet, choixVerbe, choix2 , complementPhrase)
            print(choixArticle, choixSujet, choixVerbe, choix3 , complementPhrasePluriel)
            n1 = '\n'
            phrases = ['La phrase :'+" Il y'a "+choixArticle+' '+choixSujet+' qui '+choixVerbe+' les'+' '+complementPhrasePluriel+' '+finPhrase, n1,
                       choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix1+' '+complementPhrase, n1,
                       choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix2+' '+complementPhrase, n1,
                       choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix3+' '+complementPhrasePluriel]
            fichier.writelines(phrases)
        else :
            print('La phrase :',"Il y'a "+choixArticle, choixSujet,'qui ', choixVerbe, 'les', complementPhrasePluriel, finPhrase2)
            print(choixArticle, choixSujet, choixVerbe, choix1 , complementPhrase)
            print(choixArticle, choixSujet, choixVerbe, choix2 , complementPhrase)
            print(choixArticle, choixSujet, choixVerbe, choix3 , complementPhrasePluriel)
            n1 = '\n'
            phrases = ['La phrase :'+" Il y'a "+choixArticle+' '+choixSujet+' qui '+choixVerbe+' les'+' '+complementPhrasePluriel+' '+finPhrase2, n1,
                       choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix1+' '+complementPhrase, n1,
                       choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix2+' '+complementPhrase, n1,
                       choixArticle+' '+choixSujet+' '+choixVerbe+' '+choix3+' '+complementPhrasePluriel]
            fichier.writelines(phrases)
    
    
    
    
    
    
    
    fichier.close()
    i = i +1
        
        
        
        
        
        
        
        