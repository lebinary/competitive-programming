## Thoughts:

strs = ["ca","bb","ac"]


2d matrix:
[x, a]
[y, c]
[z, b]

for col : cols:
  for row : rows:
    if curr <= prev:
      break
      count++
    if row == rows-1:
      return count
return count


"ab", "ac" => correct
"ab", "aa" => incorrect

["xga","xfb","yfa"] expected = 1


["xga"
 "xfb"
 "yfa"]

xga < xfb < yfa => false

pick col 0: ga < fb < fa => false
pick col 1: xa < xb < ya => true   , count++
