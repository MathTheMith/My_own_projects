# Random Forest from Scratch
Building random forest from scratch to predict tennis match results.

## Where to Start
Start by going through notebooks 0 (0.CleanData.ipynb) to 3 (3.Predict.ipynb).
There are also other notebooks like CleanUpAusOpen.ipynb, which do other things.
My previous attempt at this project is also contained in DataAnalysis.ipynb. I corrected the data leakage there, however, I still would recommend just using notebooks 0 to 3, and forgetting about DataAnalysis.ipynb.

## Why you should not bet using my model?
Firstly, I'm just a youtuber and a CS student. Also, this was a two/three week long project.
Bookmakers are cracked, and they have the best models, which they keep a secret. I doubt that my model will ever be able to compete with them.
That being said, I think this is a fun project about how you can use Machine Learning to do some pretty cool things. Also, this model could be improved in a lot of ways, which I will briefly explain below.

I hope you enjoyed!

## To Imporve
- Take into account when a player is injured or takes a break
    - Vary K ELO factor
    - Drop ELO points if abssence
- Do further analysis on the PCA and visualize better the data to observe patterns
- Calculate more stats
    - Calculate Average ELO Rating at last tournament
    - Average ELO opponent won vs Average ELO opponent lost
    - Check regularity of a player by checking upset percentage
    - Check regularity of a player by checking 
    - Calculate the probability of win from ELO depending on best of 3 or best of 5
        - https://github.com/JeffSackmann/tennis_misc/blob/master/fiveSetProb.py
- Train on last ten/five years - Less data, but more recent
- See if probabilites of XGBoost would be better than betting odds (highly unlikely)

## Resources
- https://www.tennisabstract.com/blog/2019/12/03/an-introduction-to-tennis-elo/
- https://github.com/JeffSackmann/tennis_misc/blob/master/fiveSetProb.py
- https://github.com/JeffSackmann/tennis_atp