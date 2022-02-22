========================================================================
    C++/WinRT WeatherData.App Project Overview
========================================================================

This project demonstrates how to get started writing XAML apps directly
with standard C++, using the C++/WinRT SDK component and XAML compiler 
support to generate implementation headers from interface (IDL) files.
These headers can then be used to implement the local Windows Runtime 
classes referenced in the app's XAML pages.

Steps:
1. Create an interface (IDL) file to define any local Windows Runtime 
    classes referenced in the app's XAML pages.
2. Build the project once to generate implementation templates under 
    the "Generated Files" folder, as well as skeleton class definitions 
    under "Generated Files\sources".  
3. Use the skeleton class definitions for reference to implement your
    Windows Runtime classes.

========================================================================
Learn more about C++/WinRT here:
http://aka.ms/cppwinrt/
========================================================================
https://microsoft.sharepoint.com/teams/M365FXIntlEngOrg/_layouts/OneNote.aspx?id=%2Fteams%2FM365FXIntlEngOrg%2FSiteAssets%2FM365FX%20Int%27l%20Eng%20Org%20Notebook&wd=target%28WDX-Empower-VoiceAccess.one%7C40B712BF-C5F3-4AEB-B36D-07FA2E15E5E7%2FWeek%202%20-%20UWP%20App%20Project%7C18250FF3-B774-4240-8977-6084FBA8CF95%2F%29
onenote:https://microsoft.sharepoint.com/teams/M365FXIntlEngOrg/SiteAssets/M365FX%20Int'l%20Eng%20Org%20Notebook/WDX-Empower-VoiceAccess.one#Week%202%20-%20UWP%20App%20Project&section-id={40B712BF-C5F3-4AEB-B36D-07FA2E15E5E7}&page-id={18250FF3-B774-4240-8977-6084FBA8CF95}&end
========================================================================

The purpose of this project is to enable us with basic knowledge on XAML based UWP apps.

Please refer to the trainings page for XAML / C++/WinRT trainings.

Project name : A weather app using https://openweathermap.org/current API . Requires signup for a API key.

Specifications:
1) The application when run should display a text field (which accepts a City name) and a Submit button
2) On clicking the button the weather related details should be displayed for that city in a data grid or table below.

Things to consider:
> Project should use C++/WinRT as the base in Visual Studio
> How do you make thinfrastructuree service calls asynchronously without blocking the UI (threading)
> How do handle  errors (like network time out , or network not available)
> How do you handle business validation errors like city is not found in the list ?
> How do you model the Weather info for a city  ? (Hint : Classes )
> How do you bind the data to the XML controls (Hint: UWP MVVM model)