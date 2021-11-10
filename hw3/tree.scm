(define (data node) (car node))
(define (left node) (cadr node))
(define (right node) (caddr node))

(define (insert v tree)
    (cond ((null? tree)
	   (list v '() '())
	  )
	  ((< v (data tree)) ; of structure node (( value ) (recurse left ) ( right ))
	   (list (data tree) (insert v (left tree)) (right tree)
	   )
	  )
	  ((> v (data tree)) ; of structure node (( value ) (left ) (recurse  right ))
	   (list (data tree) (left tree) (insert v (right tree)))
	  )
	  (else tree)
    )
)

(define (member? v tree)
    (cond ((null? tree) #f
	  )
	  ((< v (data tree))
	   (member? v (left tree))
	  )
	  ((> v (data tree))
	   (member? v (right tree))
  	  )
	  (else #t)
    )
)

(define (list2tree lst) 
	(listConv lst '())
)

(define (listConv lst tree)
  (cond (	
	 (null? lst) tree
	)
        (else 
	 (listConv (cdr lst) (insert (car lst) tree))
	)
  )
)


(define (treeConv tree )
    (if (null? tree) tree
	(append (treeConv (cadr tree)) (list (car tree)) (treeConv (caddr tree)))
    )
)

(define (treeConvPre tree )
    (if (null? tree) tree
        (append (list (car tree)) (treeConvPre (cadr tree)) (treeConvPre (caddr tree)))
    )
)
