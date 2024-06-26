-- 1
SELECT title FROM movies WHERE year = 2008
-- 2 
SELECT birth FROM people WHERE name = "Emma Stone"
-- 3 
SELECT title FROM movies WHERE year >= 2018 ORDER BY title ASC
-- 4 
SELECT COUNT(title) FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE rating == 10
-- 5 
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year
-- 6
SELECT AVG(rating) FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE year = 2012
-- 7 
SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title
-- 8
SELECT name FROM people JOIN stars ON people.id = person_id JOIN movies ON movie_id = movies.id WHERE movies.title = "Toy Story"
-- 9
SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id WHERE movies.year = 2004 ORDER BY people.birth
-- 10
SELECT name FROM people WHERE people.id IN (SELECT DISTINCT(people.id) FROM people JOIN directors ON directors.person_id = people.id JOIN movies ON movies.id = directors.movie_id JOIN ratings ON ratings.movie_id = movies.id WHERE rating >= 9.0);
-- 11
SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id JOIN ratings ON movies.id = ratings.movie_id WHERE name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5
-- 12
SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Bradley Cooper" AND movies.title IN( SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE people.name = "Jennifer Lawrence")
-- 13
SELECT distinct(name) FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.title IN(
SELECT distinct(movies.title) FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958) AND people.name != "Kevin Bacon";
