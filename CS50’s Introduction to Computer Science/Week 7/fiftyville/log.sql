-- Will not give the answer, so i'll just send the first part of the log before the first finding of suspects
SELECT * FROM crime_scene_reports;

SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = "Humphrey Street";

SELECT activity FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

SELECT activity FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10;

SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute > 14; --5p2bi95

SELECT people.name FROM people WHERE license_plate = "5P2BI95"; -- name: Vanessa

SELECT * FROM people WHERE license_plate = "5P2BI95"; -- passport: 2963008352

SELECT transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28; -- nothing conclusive

SELECT transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%"; -- Three Transcripts

SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 14 AND 26;

SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%"; -- got eugene and the street of the ATM

SELECT account_number, amount FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"; --8 accounts

SELECT name, atm_transactions.amount FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number; --nothing conclusive

SELECT name, atm_transactions.amount FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.year = 2023 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw"; -- 8 people again

SELECT abbreviation, full_name, city FROM airports WHERE city = "Fiftyville"; --one specific airport: FiftyVille Regional Airport

SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports JOIN flights ON airports.id = flights.destination_airport_id WHERE flights.origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29; -- Earliest Flight is Laguardia Airport destined. id 36

SELECT passengers.flight_id, name, passengers.passport_number FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id WHERE flights.year = 2023 AND flights.month = 7 AND flights.day = 29; --lots of flights