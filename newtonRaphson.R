#.rs.restartR()

rm(list = ls())

setPolynomial <- function() {

  p_ <<- eval(parse(text = readline(prompt = "Enter Polynomial Coefficients: ")))

}; setPolynomial() ## Must be in vector format, e.g. c(1,2,1)

f <- function(x) { ## Horner's rule to evaluate polynomial
  
  y <- p_[1]
  
  for (i in 2:length(p_)) {
    
    y <- y * x + p_[i]
  }
  return(y)
}

fd <- function(x, h = 0.005) { ## Numerical differentiation
  
  return((f(x + h) - f(x - h))/(2 * h))
}

plotf <- function(x = seq(-1.5, 1.5, 0.1)) { ## Get approximate root visually
  
  plot(x, f(x), type = 'l')
  min(f(x))

}; plotf()

setX <- function() { ## Enter initial guess
  
  x_ <<- eval(parse(text = readline(prompt = "Enter x: ")))

}; setX()

newtonRaphson <- function(x0 = x_, tol = 0.0005, lim = 1000) {
  
  for (i in 1:lim) {
    
    x1 <- x0 - f(x0)/fd(x0)
    print(x1)
    
    if (abs(x1 - x0) < tol) {
      
      x0 <<- x0
      x1 <<- x1
      break;
    }
    x0  <- x1
  }
}; newtonRaphson();
