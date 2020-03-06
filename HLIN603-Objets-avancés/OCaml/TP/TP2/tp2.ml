(* Exo 1 *)

class min (xi : int) =
object (self)
  val mutable x = xi
  method get = x
  method set n = x <- n
  method min y = if self#get < y then self#get else y
end;;

class min_zero xi =
object
  inherit min xi
  method get = 0
end;;

let o1 = new min 4;;
let o2 = new min_zero 4;;

o1#min 2;; (* - : int = 2, min, o1*)
o1#min 7;; (* - : int = 7, min, o1*)
o2#min 2;; (* - : int = 0, min_zero, o2*)
o2#min (-2);; (* - : int = -2, min, o2*)

(* Exo 2 *)

(* 1. *)

class account b =
object (self)
  val mutable balance = 0.0
  method get = balance
  method deposit a = balance <- balance +. a
  method withdraw a = balance <- balance -. a
  method print = print_float balance; print_newline()
  initializer self#deposit b
end;;

class interest_account b =
object (self)
  inherit account b as super
  method deposit a = print_endline("deposit of interest_account");
    super#deposit a; self#interest
  method interest = balance <- balance +. 5. *. balance /. 100.
end;;

class secure_account b =
object
  inherit account b as super
  method withdraw a =
    if (balance -. a) >= 0. then super#withdraw a
    else failwith "Not enaugh money !"
end;;

class bank =
object (seft)
  val mutable list = []
  method add (a : account) = list <- a::list
  method balance = List.fold_left (fun a b -> a +. b#get) 0. list
  method print = List.iter (fun a -> a#print) list
  method fees = List.iter (fun a -> a#withdraw (a#get *. 5. /. 100.)) list
  method deposit x = List.iter (fun a -> a#deposit x) list
end;;

let a = new account 50.;;
let i = new interest_account 100.;;
let s = new secure_account 150.;;
let b = new bank;;
b#add a;;
(* b#add i;;
Error: This expression has type interest_account
       but an expression was expected of type account
       The second object type has no method interest *)
b#add s;;
b#add (i:>account);;
b#balance;;
b#print;;
b#fees;;
b#deposit 10.;;

(* 2. *)

class ['t] collection =
object
  val mutable list = []
  method add (o : 't) = list <- o::list
end;;

class ['t] bank2 =
object (*(self)*)
  inherit ['t] collection (*as super*)
  method balance = List.fold_left (fun a b -> a +. b#get) 0. list
  method print = List.iter (fun a -> a#print) list
  method fees = List.iter (fun a -> a#withdraw (a#get *. 5. /. 100.)) list
  method deposit x = List.iter (fun a -> a#deposit x) list
end;;

let a = new account 50.;;
let i = new interest_account 100.;;
let s = new secure_account 150.;;
let b = new bank2;;
b#add a;;
b#add (i:>account);;
b#add s;;
b#balance;;
b#print;;
b#fees;;
b#print;;

(* Exercice 3 *)

(* Egalité structurelle : toutes les classes ci-dessous définissent
 * des types égaux, mêmes méthodes de même type *)

(*class exp *)

class cte n  =
object
  val content = n
  method eval = content
  method print = print_int n
end;;

class inv e =
object
  val content = e
  method eval = -e#eval (*bug*)
  method print =
    print_string "(-";
    content#print;
    print_string ")"
end;;

class add (l : add) (r : add) =
object
  val left = l
  val right = r
  method eval = left#eval + right#eval
  method print =
    print_string "(";
    left#print;
    print_string " + ";
    right#print;
    print_string ")"
end;;

class sub (l : sub) (r : sub) =
object
  val left = l
  val right = r
  method eval = left#eval - right#eval
  method print =
    print_string "(";
    left#print;
    print_string " - ";
    right#print;
    print_string ")"
end;;

class mul (l : mul) (r : mul) =
object
  val left = l
  val right = r
  method eval = left#eval * right#eval
  method print =
    print_string "(";
    left#print;
    print_string " * ";
    right#print;
    print_string ")"
end;;

class div (l : div) (r : div) =
object
  val left = l
  val right = r
  method eval = left#eval / right#eval
  method print =
    print_string "(";
    left#print;
    print_string " / ";
    right#print;
    print_string ")"
end;;

let e = new add (new cte 1) (new cte 2);;
e#eval;;
e#print;;

(* Est-til nécessaire de construire une super-classe expr ? - Non car tout les types sont égaux *)
(* Exo pratique : Coder une classe expr et op *)

(* Exo 4 *)

class ['t] abr (v : 't) =
object
  val value = v
  (*  val *)
  method get = value
(*method insert =
  method find =
  method remove =*)
end;;

(*class ['t] abr =
object
  val root *)

let n1 = new abr 1;;
n1#get;;
