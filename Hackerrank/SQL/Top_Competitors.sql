select h.hacker_id, h.name
from submissions as s
    join hackers as h on h.hacker_id = s.hacker_id
    join challenges as c on c.challenge_id = s.challenge_id
    join difficulty as d on d.difficulty_level = c.difficulty_level
where 
    s.score = d.score
group by 
    h.hacker_id, h.name
having
    count(*) > 1
order by
    count(*) desc,
    h.hacker_id


