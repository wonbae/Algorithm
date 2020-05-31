/*A median is defined as a number separating the higher half of a data set from the lower half. 
Query the median of the Northern Latitudes (LAT_N) from STATION and round your answer to  decimal places.
*/

Select round(S.LAT_N,4) mediam 
from station S 
where (select count(Lat_N) 
       from station 
       where Lat_N < S.LAT_N ) = (select count(Lat_N) 
                                  from station 
                                  where Lat_N > S.LAT_N)
