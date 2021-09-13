import {NgModule} from '@angular/core';
import {RouterModule, Routes} from '@angular/router';
import {AppComponent} from "./app.component";
import {NavBarComponent} from "./all-components/nav-bar/nav-bar.component";
import {FormComponent} from "./all-components/form/form.component";
import {ProjectsComponent} from "./all-components/projects/projects.component";
import {DepartmentsComponent} from "./all-components/departments/departments.component";
import {WinnersComponent} from "./all-components/winners/winners.component";

const routes: Routes = [
  {path: 'signup', component: FormComponent},
  {path: 'projects', component: ProjectsComponent},
  {path: 'departments', component: DepartmentsComponent},
  {path: 'raffle', component: WinnersComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule {
}
