ActionFirst()
{
	/* Flights */

	web_url("Search Flights Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
			
	web_reg_save_param_ex(
		"ParamName=OFlight",
    	"LB=name=\"outboundFlight\" value=\"",
    	"RB=\"",
    	"Ordinal=all",
    	"NotFound=Warning",
			LAST);
		
	web_reg_save_param_ex(
		"ParamName=PriceTickets",
    	"LB=td align=\"center\">$ ",
    	"RB=<\/TD>",
    	"Ordinal=all",
    	"NotFound=Warning",
		LAST);
	
	
	/* Continue 1 */
	
	web_submit_data("reservations.pl", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DepartCity}", ENDITEM, 
		"Name=departDate", "Value={DateOut}", ENDITEM, 
		"Name=arrive", "Value={ArrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={DateTo}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=62", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	return 0;
}
