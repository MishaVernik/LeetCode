;; TASK 1
(defun sum-lst(some-lst)
  (if (null some-lst)
      0
      (+ (sum-lst (cdr some-lst)) (car some-lst))))


;; TASK 2
(defun inc-1-lst(lst)
  (unless (endp lst)
    (cons (1+ (first lst))
	  (inc-1-lst (cdr lst)))))
;; TASK 3
(defun my-reverse(lst)
  (labels ((my-reverse (lst acc)
     (if (endp lst)
          acc
          (my-reverse (rest lst) (cons (first lst) acc)))))
      (my-reverse lst '())))

;; TASK 4
(defun delete-repeats(lst)
  (when lst
      (if (member (car lst) (cdr lst))
	  (delete-repeats (cdr lst))
	  (cons (car lst) (delete-repeats (cdr lst))))))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; TESTS ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TASK 1
(defun check-sum-lst (input expected)
  (let ((result (sum-lst input)))
    (equal result expected)))

(defun test-sum-lst (name input expected)
  (print "te")
  (or (check-sum-lst input expected)
      (format T "~A failed~%" name)))

(defun run-sum-lst-tests ()
  (test-sum-lst "sum-1" '(-1 2 3) 4)
  (test-sum-lst "sum-2" nil 0)
  (test-sum-lst "sum-3" '(-1 -2 0 0 0 0) -3)
  (test-sum-lst "sum-4" '(5 5 5 5) 20))
;; TASK 2
(defun check-inc-1-lst (input expected)
  (let ((result (inc-1-lst input)))
    (equal result expected)))

(defun test-inc-1-lst (name input expected)
  (print "te")
  (or (check-inc-1-lst input expected)
      (format T "~A failed~%" name)))

(defun run-inc-1-lst-tests ()
  (test-inc-1-lst "inc-1" '(-1 2 3) '(0 3 4))
  (test-inc-1-lst "inc-2" nil nil)
  (test-inc-1-lst "inc-3" '(-1 -2) '(0 -1))
  (test-inc-1-lst "inc-4" '(5 5 5 5) '(6 6 6 6)))
;; TASK 3
(defun check-my-reverse (input expected)
  (let ((result (my-reverse input)))
    (equal result expected)))

(defun test-my-reverse (name input expected)
  (or (check-my-reverse input expected)
      (format T "~A failed~%" name)))

(defun run-my-reverse-tests ()
  (test-my-reverse "my-reverse-1" '(1 2 3) '(3 2 1))
  (test-my-reverse "my-reverse-2" '(1 2) '(2 1))
  (test-my-reverse "my-reverse-3" '(a b c) '(c b a))
  (test-my-reverse "my-reverse-4" nil nil))
;; TASK 4
(defun check-delete-repeats (input expected)
  (let ((result (delete-repeats input)))
    (equal result expected)))

(defun test-delete-repeats (name input expected)
  (or (check-delete-repeats input expected)
      (format T "~A failed~%" name)))

(defun run-delete-repeats-tests ()
  (test-delete-repeats "delete-repeats-1" '(1 1 1 2 2 3) '(1 2 3))
  (test-delete-repeats "delete-repeats-2" '(2 2 2 2 2 2 2) '(2))
  (test-delete-repeats "delete-repeats-3" '(1 2 3 4 5) '(1 2 3 4 5))
  (test-delete-repeats "delete-repeats-4" '(1 1 1 2 2 1 3 3 2 3 1) '(2 1 3))
  (test-delete-repeats "delete-repeats-5" nil nil)
  (test-delete-repeats "delete-repeats-6" '(nil nil nil) '(nil)))
;; RUN ALL 
(defun run-all-test()
  (run-sum-lst-tests)
  (run-inc-1-lst-tests)
  (run-my-reverse-tests)
  (run-delete-repeats-tests))