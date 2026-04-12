# Prosjekt TDT4102

Laget av Jostein Graff og Erland Handegard

## Dokumentasjon

Vi har prøvd å lage vår egen variant av spillet Terraria. Nå har vi lagt til mining og at man kan plokke opp blokker samt en prototype av en mob: zebraen. 
Spillet er ikke komplett, men vi har implementert så mye som vi rakk på tiden som ble gitt. 

I main filen er hovedgameloopen som kjører for hver frame. I src mappen ligger kildekoden til alle medlemsfunksjonen. Per nå har vi 5 objekt som er 
player, world, itemDrop(for items på bakken), GameWindow og varianter av mobs. De viktigste funksjonene er update kamera og move funksjonene
ettersom at de lar spilleren og kameraet til å bevege seg. 

World klassen holder på alle blokkene til verdenen i en liste som hentes ut av updateWindow() for å tegne til vinduet. Vi henter ut kun gitte blokker som defineres 
av en funksjon kalt blokks to render. Kameraets posisjon er satt til å følge etter spilleren som kan løpe rundt i verden. 

itemDrop var en ny klasse som vi lagde for å hjelpe oss med å plokke opp items. Vær gang spilleren ødelegger en blokk så brukte vi emplaceBack i en liste i worlds. 
Om posisjonen var lik med spiller økte vi forekomsten av denne i spilleren. 

Mobs per nå er programert til å følge etter spilleren. Vi fikk ikke implementert damage enda, men alle variablene ligger egentlig klare. 

I tillegg ville vi at alle tingene skulle kunne lagres i textfiler slik at vi kunne lagre progresjonen. Desverre fikk vi aldri implementert en savefunksjon som
lagrer verdiene i tekstfiler slik at vi kan lagre all progresjonen. Vi tenkte å sette noen knapper nede i venstre gjørne men fikk ikke tid. 

Da vi lagde random world generation hadde vi lyst til å bruke perlin noise for å generere tilfeldig terreng. Dette ble veldig omfattende å lage selv så her importerte
vi en headerfil som var offentlig for bruk på github. Den har ikke vi laget. I window klassen fikk vi veldig dårlig tid så generate background er
laget med AI. I tillegg er image cache også laget ved hjelp av AI. Vi slet med performance. Dette kom av at vi lagret bilder på disken og hentet dem derfra
på vær frame. Her brukte vi AI for å hjelpe oss. Ellers er hele koden noe vi har produsert selv og alt er laget av oss.

## Refleksjonsnotat: Erland Handegard

Jeg lærte utrolig mye i dette prosjektet. Både om c++ språket og om hvordan man lager spill. Det jeg begynte å implementere var kameraet og verden. 
Dette var en god ide spesielt er kameret lurt å implementere tidlig siden det bare skal få informasjon uten å gi noe. 
Derretter bygde vi videre på spilleren. Etter vi hadde en spiller som kunne gi fra seg posisjonen branchet vi ut og lagde mobs. 

En ting jeg mest sannsynlig hadde endret om jeg hadde fått gjort tin om igjen var å endre blokkene til egen definerte objekter og ikke strings. Vi burde heller
bare hatt id til noen objekter i vektorene inne i verden generering. Slik de er nå ble det veldig vanskelig å lage funksjonen som skulle lese filene
og de er enda vanskeligere å tolke. Grunnen til at det ble gjort slik er egentlig bare at jeg har lite kodeerfaring. 

## Refleksjonsnotat: Jostein Graff
