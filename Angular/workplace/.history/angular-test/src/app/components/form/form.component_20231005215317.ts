import { Component } from '@angular/core';
import { NgForm } from '@angular/forms';
import { FormControl, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-form',
  templateUrl: './form.component.html',
  styleUrls: ['./form.component.css']
})
export class FormComponent {
  on_Submit(form: NgForm) {
    console.log(form.valid);
  }

  onSubmit() {
    console.log(this.contactForm.value);
    console.log(this.contactForm.value.fullName?.firstName);
    console.log(this.contactForm.value.fullName?.lastName);
    console.log(this.contactForm.get();
  }

  contactForm = new FormGroup({
    fullName: new FormGroup({
      firstName: new FormControl(),
      lastName: new FormControl()
    }),
    phone: new FormControl(66666666666),
  });

}
