(* Exercice 1 *)

((fun x -> x + 1) 1);;


let a1 = fun x -> x + 1;;
a1 1;;

let a2 x = x + 1;;
a2 1

let a3 = function x -> x + 1;;
a3 1;;

(* "1::[2]" = "(cons 1 '(2))" *)

(* Q1. Inverse les éléments d'une liste *)
let rec rev = function
  | [] -> []
  | e::tl -> (rev tl) @ [e];;

rev [1; 2; 3; 4; 5];;

(* Donne le nombre d'élément donnée dans une liste *)
let rec size l = match l with
    | [] -> 0
    | e::tail -> 1 + (size tail);;

size [1; 2; 3];;

(* Q2. Donne le nombre d'occurrences d'un élément donné dans une liste *)
let rec occ e l = match l with
  | [] -> 0
  | h::tl -> if h == e then 1 + (occ e tl) else occ e tl;;

occ 3 [1; 2; 3; 3; 3; 4];;

(* Q3. Teste si une liste est triée ou non *)
let rec is_sorted l = match l with
  | [] -> true
  | [e] -> true
  | a :: b :: tl -> (a <= b) && (is_sorted (b :: tl));;

let l1 = [1; 2; 3; 4; 5];;
let l2 = [5; 4; 3; 2; 1];;
is_sorted l1;;
is_sorted l2;;

(* Q4. Réalise une insertion triée d'un élément donnée dans une liste triée *)
let rec insert x l = match l with
  | [] -> [x]
  | e :: tl ->
     if x <= e then x :: e :: tl
     else e :: (insert x tl);;

insert 4 [1; 2; 3; 5];;

(* Q5. Trie une liste selon l'algorithme de tri par insertion *)
let rec insertion_sort = function
  | [] -> []
  | e :: tl -> insert e (insertion_sort tl);;

insertion_sort [5; 4; 3; 2; 1];;

(* Exercice 2 *)

(* Q1 *)
type form =
  | Top | Bot
  | Var of string
  | Not of form
  | And of form * form
  | Or of form * form
  | Imp of form * form
  | Equ of form * form;;

(* Q2 *)
let rec string_of_form = function
  | Top -> "true"
  | Bot -> "false"
  | Var n -> n
  | Not f -> "~" ^ (string_of_form f)
  | And (f1, f2) ->
     "(" ^ (string_of_form f1) ^ " /\\ " ^ (string_of_form f2) ^ ")"
  | Or (f1, f2) ->
     "(" ^ (string_of_form f1) ^ " \\/ " ^ (string_of_form f2) ^ ")"
  | Imp (f1, f2) ->
     "(" ^ (string_of_form f1) ^ " => " ^ (string_of_form f2) ^ ")"
  | Equ (f1, f2) ->
     "(" ^ (string_of_form f1) ^ " <=> " ^ (string_of_form f2) ^ ")";;

(* Q3 *)

let rec simp_and = function
  | (f, Top) | (Top, f) -> f
  | (f, Bot) | (Bot, f) -> Bot
  | (f1, f2) -> And (f1, f2);;

let rec simp_or = function
  | (f, Top) | (Top, f) -> Top
  | (f, Bot) | (Bot, f) -> f
  | (f1, f2) -> Or (f1, f2);;

let rec simp_imp = function
  | (f, Top) | (Bot, f) -> Top
  | (Top, f) -> f
  | (f, Bot) -> Not f
  | (f1, f2) -> Imp (f1, f2);;

let rec simp_equ = function
  | (f, Top) | (Top, f) -> f
  | (f, Bot) | (Bot, f) -> Not f
  | (f1, f2) -> Equ (f1, f2);;


let rec simp_form = function
  | And (f1, f2) ->
     let f1' = simp_form f1
     and f2' = simp_form f2 in
     simp_and(f1', f2')
  | Or (f1, f2) -> 
     let f1' = simp_form f1
     and f2' = simp_form f2 in
     simp_or(f1', f2')
  | Imp (f1, f2) ->
    let f1' = simp_form f1
    and f2' = simp_form f2 in
    simp_imp(f1', f2')
  | Equ (f1, f2) ->
     let f1' = simp_form f1
     and f2' = simp_form f2 in
     simp_equ(f1', f2')
  | f -> f;;

(*#trace simp_form;;
let f1 = Imp (Bot, Var "A");;
string_of_form f1;;
simp_form f1;;
string_of_form(simp_form f1);;*)

(* Exo 2 *)
let a = 'A';;
let b = 'B';;
let i1 = [(a, Top); (b, Bot)];;
val assoc ass1 = a [(a, Top); (b, Bot)];;

(* Tests *)

let f2 = Not (Var "A");;
let f3 = And ((Var "A"), Top);;
let f4 = Or (Bot, Var "A");;
let f5 = Imp (Bot, Var "A");;
let f6 = Equ ((Not (Var "A")), Var "A");;

string_of_form f2;;
string_of_form f3;;
string_of_form f4;;
string_of_form f5;;
string_of_form f6;;

simp_form f2;;
simp_form f3;;
simp_form f4;;
simp_form f5;;
simp_form f6;;
