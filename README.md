# Edoc-Magorp-Exp-Calculator

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Magorp_edoc_exp_Calculator.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 3. Project 14.
A theoretical calculator for a game in which a player may use "candies" to evolve "edocs" into "margorps". Calculation complexity comes from two factors: 1) edocs and margorps may both be transferred for candy at a 1:1 ratio; 2) evolving an edoc provides one candy.
Demonstrates knowledge of complex flow control managing multiple variables, creation of complex formulas taking multiple parameters, and usage of input/output streams.

Written using Microsoft Visual Studio. 

## Algorithm

    1. receive input for # of edocs and # of candies
		2. while evolution is theoretically possible, given all variables (margorp, edoc, and candy)
			2a. determine if evolution is practically possible; if so, evolve
			2b. if not, determine if evolution is possible through transferring margorps and edocs;
				if so, transfer margorps first then edocs until evolution is practically possible
			2c. if there are no margorps, determine if evolution is possible through transferring only edocs
				(it must be, if evolution is theoretically possible and the previous branches are false!)
					2ca. transfer edocs until evolution is practically possible
		3. output total experience gained
		4. prompt user whether to continue

## Requirements
No requirements or modules needed for running this program. 
