datatype tree = empty | node of int * tree * tree;

fun insert empty v = node(v,empty,empty) 
    |insert (node(d,l,r)) v = if v < d then node(d,insert l v,r)
				else if v > d then node(d,l,insert r v)
				else node(d,l,r); 


fun member(v,empty) = false
    |member(v,node(d,l,r)) = if d = v then true
				else if d > v then member(v,l)
				else member(v,r);

val build = foldl (fn (v,t) => insert t v) empty;

fun inorder empty = []
    |inorder (node(d,l,r)) = inorder l @ d::inorder r;

fun preorder empty = []
    |preorder (node(d,l,r)) = d::preorder l @ preorder r;
