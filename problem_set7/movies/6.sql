-- write a SQL query to determine the average rating of all movies released in 2012
SELECT avg(rating) AS avg_rating2012
FROM ratings
INNER JOIN movies
ON ratings.movie_id = movies.id
WHERE movies.year = 2012;