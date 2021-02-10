# CBNST
> C Programs for CBNST with user-friendly input-module.

__List of Contents__
1. Bisection Method

## Bisection Method

### Algorithm
* Find two points say a and b such that a<b and f(a)*f(b)<0
* Find the midpoint of a and b, say "X"
* X is the root of the given function if f(x) = 0; else follow the next step.
* If f(X)*f(b) < 0 let a=X
* Else if f(x)*f(a), let b = X
* Repeat above theree steps until f(X) = 0
