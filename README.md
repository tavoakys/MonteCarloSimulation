# Monte Carlo Simulations in C++

---

## What are Monte Carlo Simulations?

Monte Carlo simulations are a class of computational algorithms that rely on repeated random sampling to model and analyze complex systems. They are widely used in finance, physics, engineering, and many other disciplines to approximate the probability of different outcomes when the underlying process is uncertain.

---

## How Monte Carlo Simulations Work in Finance

In finance, Monte Carlo simulations are often used to model the price evolution of assets. A stock price can be modeled using **Geometric Brownian Motion (GBM)**, which assumes that the log of the stock price follows a random walk with drift.

The formula for simulating stock price paths is:

$$
S_{t+\Delta t} = S_t \cdot \exp \Big( ( \mu - \tfrac{1}{2}\sigma^2 ) \Delta t + \sigma \sqrt{\Delta t} \cdot Z \Big)
$$

Where:  
* $S_t$ = stock price at time $t$  
* $\mu$ = expected return (drift)  
* $\sigma$ = volatility  
* $\Delta t$ = time increment  
* $Z$ = random draw from a standard normal distribution  

By simulating many paths and analyzing their distribution, we can estimate expected values, risks, and probability distributions for future prices.

---

## Project Overview

This C++ project implements a Monte Carlo simulation of stock prices using the GBM model. Specifically, it does the following:

* Simulates multiple price paths for a stock given initial parameters.  
* Calculates and outputs key statistics like the **average final price** and **variance**.  
* Visualizes stock price paths over time using `matplotlib-cpp`.  
* Displays a histogram of final simulated stock prices.  

---

## Example Run

You can run the program with optional parameters: 
`S0` = Initial stock price (default: 100)
`mu` = Expected return (default: 0.08)
`sigma` = Volatility (default: 0.2)
`T` = Time horizon in years (default: 1)
`steps` = Number of timesteps (default: 252)
`paths` = Number of simulated paths (default: 10000)
`seed` = RNG seed (default: random_device)

### Sample Output:

```
=== Monte Carlo Simulation ===
S0=100  mu=0.08  sigma=0.2  T=1  steps=252  paths=10000  seed=1961779376
Average Final Price=108.466   Variance of Final Price=483.522

Time elapsed: 9807.36 ms
```

Two plots will appear:

![Simulated Paths](https://github.com/tavoakys/MonteCarloSimulation/blob/master/Monte_Carlo_Simulation_Paths.png)
![Final Price Distribution](https://github.com/tavoakys/MonteCarloSimulation/blob/master/Final_Price_Distribution.png)

---

## Importance of Monte Carlo Simulations

Monte Carlo simulations are powerful because they allow us to:
* Model uncertainty – estimate outcomes where analytical solutions are impossible.
* Perform risk analysis – evaluate volatility and tail risks in asset pricing.
* Support decision making – help investors and risk managers plan under uncertainty.
* Learn quantitatively – visualize stochastic processes and probability distributions.

---

## Skills Demonstrated

This project highlights both programming and quantitative finance skills:
* C++ fundamentals – command-line argument parsing, loops, condition checks.
* Mathematical modeling – stochastic differential equations (GBM).
* Data visualization – plotting with `matplotlib-cpp`.
* Quant finance knowledge – understanding asset price dynamics and variance.

This program is a simple example of applying quantitative finance models through programming.

Check out the code [here](https://github.com/tavoakys/MonteCarloSimulation/blob/master/src/main.cpp).

---

## Resources Used

* [Article: Investopedia - Monte Carlo Simulation: What It Is, How It Works, History, 4 Key Steps](https://www.investopedia.com/terms/m/montecarlosimulation.asp)
* [Article: Investopedia - How to Use Monte Carlo Simulation With GBM](https://www.investopedia.com/articles/07/montecarlo.asp)
* [`matplotlib-cpp` library for visualization](https://github.com/lava/matplotlib-cpp)
* This README.md file was written with the assistance of GPT-5.
