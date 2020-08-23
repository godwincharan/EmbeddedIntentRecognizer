# How to define state description in csv

Each state machine is described using the following format

```
*what,is
is,the
the,weather
weather,like
like,today,in
in,Paris,New
Paris,today
New,York
York,today
today > Intent: Get Weather
-
```

* Each line in the decription gives the state and possible next state where it can progress.

* The line is tokenized using comma (,) for the state and subsequent states for transition.

* Begin state is always marked with asterisk (*).

* End state has greater than (>) symbol to inidicate it ios the end state.

* The text followed by greater than (>) gives the intent of the state machine.

* Each state machine must end with hyphen (-).

In this example

* ***what*** is begin state.

* ***today*** is end state.

* ***Intent: Get Weather*** is the intent for this state machine.

* ***like*** state has two subsequent states namely ***today*** and ***in***.
