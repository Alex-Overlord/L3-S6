(** Exo 1 **)

class min (init : int) =
object (self)
  val x = init
  method get = x
  method min y = if self#get < y then self#get else y
end;;

class min_max (init : int) =
object (self)
  inherit min init
  method max y = if self#min y = y then self#get else y
end;;

class other =
object
  method get = 1
  method min n = n - 1
  method max n = n + 1
end;;

class ['a] cell (init : 'a) =
object
  val mutable cont = init
  method get = cont
  method set n = cont <- n
end;;

let m = new min 1;;
let mm = new min_max 2;;
let o = new other;;
let c = new cell 1;;

let natural (o : min) = o#min(0) = 0;;
(* val natural : min -> bool = <fun> *)
let negative (o : #min) = o#min(0) = o#get;;
(* val netative : #min -> bool = <fun> *)
let positive o = o#get > 0;;
(* val positive : get : int; .. > -> bool = <fun> *)

natural m;;
(* - : bool = true *)
natural mm;;
(* Error: This expression has type min_max but an expression was
 * espected of type min. The second tupe has no method max *)
natural o;;
(* Error: This expression has type other but an expression was
 * expected of type min. The second object has no method max *)
natural (o:>min);;
(* - : bool = false *)
natural c;;
(* Error: Ths expression has type int cell but an expression was
 * expreted of type min. The second object type has no method set *)
negative m;;
(* - : bool = false *)
negative mm;;
(* - : bool = false *)
negative o;;
(* - : bool = false *)
negative c;;
(* Error: This expression has type int cell but an expression was
 * expreted of type #min. The first object type has no method min *)
positive m;;
(* - : bool = true *)
positive mm;;
(* - : bool = true *)
positive o;;
(* - : bool = true *)
positive c;;
(* - : bool = true *)

(** Exo 2 **)

class virtual ['a] add_magma =
        object
          method virtual add : 'a -> 'a -> 'a
        end;;

class virtual ['a] mul_magma =
        object
          method virtual mul : 'a -> 'a -> 'a
        end;;

class virtual ['a] add_monoid =
        object
          inherit ['a] add_magma
          method virtual add_id : 'a
        end;;

class virtual ['a] mul_monoid =
        object
          inherit ['a] mul_magma
          method virtual mul_id : 'a
        end;;

class virtual ['a] add_group =
        object
          inherit ['a] add_monoid
          method virtual add_reverse : 'a
        end;;

class virtual ['a] ring =
        object
          inherit ['a]
