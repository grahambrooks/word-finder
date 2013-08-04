word-finder
===========

word-finder reads a string of characters supplied on the command line
and finds words of 3 or more characters.

word-finder uses the aspell C api to check each permutation of
characters.
<pre>
word-finder rdseef
</pre>
produces 

<pre>
def
eds
ere
fed
fee
fer
red
ref
res
see
deer
feds
feed
fees
free
reds
reed
reef
refs
seed
seer
sere
serf
defer
feeds
freed
frees
reeds
reefs
defers
</pre>
