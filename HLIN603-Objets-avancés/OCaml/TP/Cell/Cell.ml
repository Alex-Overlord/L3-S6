(* Première classe *)

class cell =
object
  val content = 0
  method get = content
end;;

let o = new cell;;
o#get;;
o#content;;

(* Polymorphisme *)

class ['a] cell (n : 'a) =
object
  val content = n
  method get = content
end;;

let o = new cell 1;;
o#get;;
let o = new cell true;;
o#get;;

(* Constructeurs fonctionnels, application partielle *)

let f = new cell;;
let o = f 1;;
o#get;;
let o = f true;;
o#get;;

(* Types de classes *)

class type ['a] cell_type  =
  object
    method get : 'a
  end;; (* bug, copier coller directement dans l'interpréteur *) 


class type ['a] cell n : ['a] cell_type =
  object
    val content = n
    method get = content
  end;; (* bug, copier coller directement dans l'interpréteur *)

class ['a] cell (n : 'a) =
object
  val mutable content = n
  method get = content
  method set n = content <- n
end;;
(*
class ['a] cell :
        'a ->
        object val mutable content : 'a
          method get : 'a method set : 'a -> unit end (* bug *)
 *)
let o = new cell 0;;
o#get;;
o#set 1;;
o#get;;
