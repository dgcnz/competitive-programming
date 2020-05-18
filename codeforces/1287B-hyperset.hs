import Data.List
import qualified Data.Set as S

--  @idea (Taken from Editorial). A set is uniquely defined by two of its members,
--      say A and B. At position i, if A and B are equal, then C has to be equal, 
--      otherwise it has to be the remaining character.
--      Instead of try all nC3 combinations, pick all unique pairs, generate its
--      candidate and see if it is one of the cards.
--      To avoid repetition, one can force C to be less than A or bigger than B.

candidate :: String -> String -> String
candidate [] [] = []
candidate (x:xs) (y:ys) = cur:candidate xs ys
    where 
        cur = if (x == y) then x else (head $ "SET" \\ [x, y])

getAllMatches :: [String] -> [(String, String, String)]
getAllMatches cards = [(a, b, c) |
    (a:bs) <- tails cards,
    b <- bs, 
    let c = candidate a b,
    c < a,
    S.member c cards']
    where cards' = S.fromAscList cards

solve :: [String] -> Int
solve cards = length . getAllMatches . sort $ cards

main = do
    _ <- getLine
    strings <- words <$> getContents
    print $ solve strings
