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
Noe av det kuleste vi klarte å implementere var random world generation, med perlin noise. 

itemDrop var en ny klasse som vi lagde for å hjelpe oss med å plokke opp items. Vær gang spilleren ødelegger en blokk så brukte vi emplaceBack i en liste i worlds. 
Om posisjonen var lik med spiller økte vi forekomsten av denne i spilleren. 

Mobs per nå er programert til å følge etter spilleren innenfor en gitt margin. Vi fikk ikke implementert damage enda, men alle variablene ligger egentlig klare. Zebraen eller Ground for ground mobile enteties er en underklasse av mobile enteties for å kunne lage flere mobs etterhvert. Zebra er da en prototype på dette. Mobsene tegnes til verden gjennom en vektor med mobpekere og ved algoritme basert bevegelse og ikke etterfølgelse av spiller vil flere enheter kunne bevege seg fritt på skjermen. Det var her i gjort klar en random funksjon som ikke ble tatt i bruk. 

Basisen med mobsene var ide fra forelesningen om å ha de som pekere i en vektor. Disse raskt endret til smartpekere. Ved bevegelsene av Zebraen tok jeg utgangspunkt i bevegelsene til Player og gjorde de tilpassningene som trengtes. Her tok jeg også i bruk enum class for å holde styr på tidligere colisjoner med verden, noe som muligjorde at ground mobs kan komme seg over hindringer. 

For å få mobsene til å kunne få forskjellige skins etter hvert ble konstruktøren endret til å også ta inn en sting/filsti for dette.

I tillegg ville vi at alle tingene skulle kunne lagres i textfiler slik at vi kunne lagre progresjonen. Desverre fikk vi aldri implementert en savefunksjon som
lagrer verdiene i tekstfiler slik at vi kan lagre all progresjonen. Vi tenkte å sette noen knapper nede i venstre gjørne men fikk ikke tid. 

Da vi lagde random world generation hadde vi lyst til å bruke perlin noise for å generere tilfeldig terreng. Dette ble veldig omfattende å lage selv så her importerte
vi en headerfil som var offentlig for bruk på github. Den har ikke vi laget. I window klassen fikk vi veldig dårlig tid så generate background er
laget med AI. I tillegg er image cache også laget ved hjelp av AI. Vi slet med performance. Dette kom av at vi lagret bilder på disken og hentet dem derfra
på hver frame. Her brukte vi AI for å hjelpe oss. Ellers er hele koden noe vi har produsert selv og alt er laget av oss.

## Refleksjonsnotat: Erland Handegard

Jeg lærte utrolig mye i dette prosjektet. Både om c++ språket og om hvordan man lager spill. Det jeg begynte å implementere var kameraet og verden. 
Dette var en god ide spesielt er kameraet lurt å implementere tidlig siden det bare skal få informasjon uten å gi noe. 
Derretter bygde vi videre på spilleren. Etter vi hadde en spiller som kunne gi fra seg posisjonen branchet vi ut og lagde mobs. 

En ting jeg mest sannsynlig hadde endret om jeg hadde fått gjort ting om igjen var å endre blokkene til egen definerte objekter og ikke strings. Vi burde heller
bare hatt id til noen objekter i vektorene inne i verden generering. Slik de er nå ble det veldig vanskelig å lage funksjonen som skulle lese filene
og de er enda vanskeligere å tolke. Grunnen til at det ble gjort slik er egentlig bare at jeg har lite kodeerfaring. 

## Refleksjonsnotat: Jostein Graff

Det har vært utrolig spennede å jobbe med en egen oppbygning av prosjektet. 
Jeg har lært veldig mye i løpet av prosjektet og føler jeg har fått en mye bedre forståelse for oppbyggnignen av C++ og objekt orientert programmering. I starten var det litt trått og ikke alltid like lett å vite i hvilken ende man skulle jobbe. Når vi derimot kom oss litt over kanten ble arbeide veldig givende. 
Jeg er veldig fornøyd med startstrukturen på arbeidet, men skulle gjerne sett at delene hadde kommet litt lengre. Tror likevel at valget om å få noen ting til å funke bra har vært en god prioritering og kan godt tenke meg å videre utvikle spillet i eksamensperioden da med spesifikke pensum deler i bakhodet. 
