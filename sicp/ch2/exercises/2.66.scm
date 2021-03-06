(define (lookup key tree)
  (cond ((null? tree) #f)
        ((equal? key (entry tree)) (entry tree))
        ((< key (entry tree)) (lookup key (left-branch tree)))
        (else (lookup key (right-branch tree)))))
