import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { NavBarComponent } from './all-components/nav-bar/nav-bar.component';
import { FormComponent } from './all-components/form/form.component';
import { ProjectsComponent } from './all-components/projects/projects.component';
import { DepartmentsComponent } from './all-components/departments/departments.component';
import { WinnersComponent } from './all-components/winners/winners.component';

@NgModule({
  declarations: [
    AppComponent,
    NavBarComponent,
    FormComponent,
    ProjectsComponent,
    DepartmentsComponent,
    WinnersComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
