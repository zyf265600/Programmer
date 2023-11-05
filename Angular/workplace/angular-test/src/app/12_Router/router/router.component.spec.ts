import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RouterComponent } from './router.component';

describe('RouterComponent', () => {
  let component: RouterComponent;
  let fixture: ComponentFixture<RouterComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [RouterComponent]
    });
    fixture = TestBed.createComponent(RouterComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
