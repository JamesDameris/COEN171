
(define(filter f lst)
    (cond
        ((null? lst) lst
        ((f(car lst))
         (cons(car lst)(filter f (cdr lst)))))
        (else (filter f (cdr lst)))))


(define(quicksort lst)
    (if (null? lst) '()
        (let ((x (car lst))
              (xs (cdr lst)) )
              (append (quicksort 
                            (filter (f(x')(< x' x)) xs))
              (list x) 
              (quicksort
                    (filter (f(x')(>= x' x)) xs))))))
                        
