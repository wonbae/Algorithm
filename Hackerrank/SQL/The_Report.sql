select if(g.grade > 7, s.name, null), g.grade, s.marks 
from students as s, grades as g
where s.marks between g.min_mark and g.max_mark 
order by g.grade desc, s.name
