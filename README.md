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

## Resources Used

* [Article: Investopedia - Monte Carlo Simulation: What It Is, How It Works, History, 4 Key Steps](https://www.investopedia.com/terms/m/montecarlosimulation.asp)
* [Article: Investopedia - How to Use Monte Carlo Simulation With GBM](https://www.investopedia.com/articles/07/montecarlo.asp)
* This README.md file was written with the assistance of GPT-5.
