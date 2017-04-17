#!/bin/sh

sed -n '30,984p' | 

#search and select just the lines that contain both English and Hawaiian vocabulary
grep "<\(td\)>.\+</td>" |

#delete every other line starting from the first English word
sed '1~2d' | 

#substitute all angle-bracketed things with nothing, effectively deleting them
sed 's/<[^>]*>//g' | 

#treat upper as lower case letters
tr '[:upper:]' '[:lower:]' |

#replace all commas followed by spaces with single newlines (for the alternate translations)
sed 's/, /\n/g' |

#remove all leading spaces in the list
sed 's/    //g' |

#treat the ` (ASCII grave accent) as if it were a ' (ASCII apostrophe)
sed "s/\`/\'/g" | 

#delete any lines containing 1 or more non-Hawaiian letters
sed "/[^pk'mnwlhaeiou]/d" |

#sort the remaining list of words, removing any duplicates
sort -u


