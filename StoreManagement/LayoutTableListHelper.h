#pragma once

class CLayoutTableListHelper
{
public:
	 static void layoutPageForCategories(std::ostream& stream, int from, int records, int selectedLine);
	 static void layoutPageForProducts(std::ostream& stream, int from, int records, int selectedLine);
	 static void layoutPageForInvoices(std::ostream& stream, int from, int records, int selectedLine);
	 static void layoutPageForOrders(std::ostream& stream, int from, int records, int selectedLine);
};

