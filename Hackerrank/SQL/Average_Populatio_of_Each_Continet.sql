select ct.continent, FLOOR(avg(ci.population))
from country as ct, city as ci
where ci.countrycode = ct.code
group by ct.continent
