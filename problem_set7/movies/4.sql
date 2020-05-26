-- write a SQ query to determine the number of movies with an IMBD rating of 10.0
SELECT count(movie_id) AS tenstar_movies
FROM ratings
WHERE rating = 10.0;